
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.MutableTreeNode;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreePath;
import javax.swing.tree.TreeSelectionModel;
import java.util.Scanner;


public class TextTreeApp
{
	//Declarations
	
	protected static TextTree myTree;
	protected static TreeNode myNode;
	
	protected JButton editLabel;
    protected JButton editContent;
	protected JButton saveLabel;
	protected JButton saveContent;
    protected JButton add;
    protected JButton remove;
    protected JButton search;

	protected JTextArea label;
    protected JTextArea content;
    protected JTextField children;
    protected JTextField searchField;
	protected JTextField searchResult;
    protected JTextField myTitle;
    protected JTextField list;
    protected JLabel resultText;
    
    protected JScrollPane labelScroll;
    protected JScrollPane contentScroll;
    protected JScrollPane TreeNodeScroll;
    protected JScrollPane childrenScroll;

    protected JFrame window;
    protected JPanel panel;
    
    protected JList<TreeNode> treeNodes;
    protected JList<String> dummyList;
    protected JList<String> childrenList;
    protected DefaultListModel listModel; 
    
    protected JTree tree;
	protected DefaultMutableTreeNode root;
	protected DefaultTreeModel treeModel;
	
	protected JMenuBar menuBar;
	protected JMenu file;
	protected JMenu edit;
	protected JMenuItem save;
	protected JMenuItem exit;
	protected JMenuItem clear;
	
    protected String currentLabel;
    protected static String[] childrenListData = {" "}; 
    protected static int totalNodeCount = 0;
	
    //Main
    
    public static void main(String argv[]) throws IOException
    {            
        myNode = new TreeNode();
        myTree = new TextTree(); 

        myTree.addNode(myNode, "Global", "Click add to add nodes");
        
        new TextTreeApp("TextTree");
    }
    
    //Class constructor
    
    public TextTreeApp(String title)
    {
    	window = new JFrame(title);
        window.setSize(1200, 700);
        window.setResizable(false);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	
        panel = new JPanel();
        panel.setLayout(null);
        window.add(panel);
        
        menuBar = new JMenuBar();
    	file = new JMenu("File");
    	edit = new JMenu("Edit");
    	save = new JMenuItem("Save");
    	exit = new JMenuItem("Exit");
    	clear = new JMenuItem("Clear");
    	
    	menuBar.add(file);
    	menuBar.add(edit);
    	file.add(save);
    	file.add(exit);
    	edit.add(clear);
    	
        window.setJMenuBar(menuBar);
        
        label = new JTextArea("label");
        label.setEditable(false);
        label.addKeyListener(new KeyPress());
        labelScroll = new JScrollPane(label);
        labelScroll.setBounds(80, 60, 500, 50);
        panel.add(labelScroll);
   
        editLabel = new JButton("Edit");
        editLabel.setBounds(80, 120, 90, 20);
        panel.add(editLabel);
        editLabel.addActionListener(new ActionHandler());
        
        saveLabel = new JButton("Save");
        saveLabel.setBounds(180, 120, 90, 20);
        panel.add(saveLabel);
        saveLabel.addActionListener(new ActionHandler());
        
        content = new JTextArea("content");
        content.setEditable(false);
        contentScroll = new JScrollPane(content);
        contentScroll.setBounds(80, 150, 500, 290);
        panel.add(contentScroll);
        
        editContent = new JButton("Edit");
        editContent.setBounds(80, 450, 90, 20);
        panel.add(editContent);
        editContent.addActionListener(new ActionHandler());
        
        saveContent = new JButton("Save");
        saveContent.setBounds(180, 450, 90, 20);
        panel.add(saveContent);
        saveContent.addActionListener(new ActionHandler());
        
        listModel = new DefaultListModel();
        childrenList = new JList<String>();
        childrenList.setModel(listModel);
        childrenScroll = new JScrollPane(childrenList);
        childrenScroll.setBounds(80, 480, 500, 140);
        panel.add(childrenScroll);
        childrenList.addListSelectionListener(new ListHandler());
        
        searchField = new JTextField("field");
        searchField.setBounds(740, 60, 280, 20);
        panel.add(searchField);
        
        search = new JButton("Search");
        search.setBounds(1030, 60, 90, 20);
        panel.add(search);
        search.addActionListener(new ActionHandler());
        
        resultText = new JLabel("results");
        resultText.setBounds(740, 90, 90, 20);
        panel.add(resultText);
        
        root = new DefaultMutableTreeNode("root");
        treeModel = new DefaultTreeModel(root);
        treeModel.addTreeModelListener(new CustomTreeModelListener());
        tree = new JTree(treeModel);
        tree.setEditable(false);
        tree.addTreeSelectionListener(new TreeHandler());
        tree.getSelectionModel().setSelectionMode(TreeSelectionModel.SINGLE_TREE_SELECTION);
        tree.setRootVisible(false);
        tree.setShowsRootHandles(true);
        TreeNodeScroll = new JScrollPane(tree);
        TreeNodeScroll.setBounds(740, 150, 380, 430);
        panel.add(TreeNodeScroll);
        
        add = new JButton("Add");
        add.setBounds(740, 600, 90, 20);
        panel.add(add);
        add.addActionListener(new ActionHandler());
        
        remove = new JButton("Remove");
        remove.setBounds(840, 600, 90, 20);
        panel.add(remove);
        remove.addActionListener(new ActionHandler());
        
        populateTree(myTree);
        
		window.setVisible(true);
		
		tree.setSelectionRow(0);
    	
    }
    
    
    //Tree Methods
    
    public void populateTree(TextTree textTree)
    {
    	TreeNode rootNode = textTree.getRoot();
    	
    	populateHelper(textTree, rootNode, root, 0);
    }
  
    public void populateHelper(TextTree textTree, TreeNode currentNode, DefaultMutableTreeNode node, int nodeIndex)
    {
	    int index;  
		
	    if(currentNode.children == null && currentNode.childrenCount == 0)
	    {
	    	addObject(node, textTree.getLabel(currentNode), true);
	    }    
		else
		{
			addObject(node, textTree.getLabel(currentNode), true);
			node = (DefaultMutableTreeNode) node.getChildAt(nodeIndex);

	        for(index = 0; index < currentNode.childrenCount; index++)
	        {   
	        	populateHelper(textTree, currentNode.children[index], node, index);
	        }
	    }   
    }
    
    public class CustomTreeModelListener implements TreeModelListener
    {
		public void treeNodesChanged(TreeModelEvent event) 
		{
            DefaultMutableTreeNode node;
            node = (DefaultMutableTreeNode)(event.getTreePath().getLastPathComponent());

            int index = event.getChildIndices()[0];
            node = (DefaultMutableTreeNode)(node.getChildAt(index));
		}

		public void treeNodesInserted(TreeModelEvent e){}
		public void treeNodesRemoved(TreeModelEvent e){} 
		public void treeStructureChanged(TreeModelEvent e){} 
    }
    
	public DefaultMutableTreeNode addNode(Object child) 
	{
		DefaultMutableTreeNode parent = null;
		TreePath path = tree.getSelectionPath();
		
		if(path == null)
		{
			parent = root;
		}
		else
		{
			parent = (DefaultMutableTreeNode) path.getLastPathComponent();
		}

	    return addObject(parent, child, true);
	}
	
	public DefaultMutableTreeNode addObject(DefaultMutableTreeNode parent, Object child, boolean visible)
	{
		DefaultMutableTreeNode childNode = new DefaultMutableTreeNode(child);
		
		treeModel.insertNodeInto(childNode, parent, parent.getChildCount());
		
		if(visible)
		{
			tree.scrollPathToVisible(new TreePath(childNode.getPath()));
		}
		
	    return childNode;
	}
	
    public DefaultMutableTreeNode removeCurrentNode() 
    {
        TreePath currentSelection = tree.getSelectionPath();
        
        TreePath parentPath = currentSelection.getParentPath();
        
        if (currentSelection != null) 
        {
            DefaultMutableTreeNode currentNode = (DefaultMutableTreeNode) currentSelection.getLastPathComponent();
            MutableTreeNode parent = (MutableTreeNode) currentNode.getParent();
            
            if (parent != null) 
            {
            	tree.setSelectionPath(parentPath);
                treeModel.removeNodeFromParent(currentNode);
            }
            
            
            return currentNode;
            
        } 
        
        return null;
    }
    
    private class TreeHandler implements TreeSelectionListener  
    {
		public void valueChanged(TreeSelectionEvent event) 
		{
			DefaultMutableTreeNode selectedElement = (DefaultMutableTreeNode) tree.getSelectionPath().getLastPathComponent();
			
			currentLabel = selectedElement.getUserObject().toString(); 

			populateTextFields(currentLabel);
			setChildrenList(currentLabel);
		}
    }
    
    public void populateTextFields(String currentLabel)
    {
    	TreeNode temp;
    	temp = myTree.searchTree(currentLabel);
    	
    	if(temp != null)
    	{
    		label.setText(myTree.getLabel(temp));
        	content.setText(myTree.getContent(temp));
    	}
    	else
    	{
			label.setText(" ");
			content.setText(" ");
    	}
    }
    
    
    public TreeNode getCurrentTreeNode()
    {
    	return myTree.getCurrentNode();
    }
    
    
    //List Methods
    
    public void setChildrenList(String currentLabel)
    {
    	int index;
    	TreeNode temp;
    	temp = myTree.searchTree(currentLabel);
    	temp.printNode();
    	
    	childrenListData = myTree.getChildrenString(temp);
    	
    	if(childrenListData != null)
    	{
    		listModel.removeAllElements();
    		for(index = 0; index < childrenListData.length; index++)
    		{
    			listModel.addElement(childrenListData[index]);
    		}
    	}
    }
    
    private class ListHandler implements ListSelectionListener
    {
        public void valueChanged(ListSelectionEvent event)
        {
            if(event.getSource() == childrenList)
            { 
            	if(!event.getValueIsAdjusting())
                {
            		populateTextFields(childrenList.getSelectedValue());
                }
            }
        }
    }
    
    //Buttons and TextField Methods
    
    private class ActionHandler implements ActionListener 
	{          	
		public void actionPerformed(ActionEvent button)
		{
			String stringValue;
			TreeNode tempTextTreeNode;
			DefaultMutableTreeNode selectedElement = (DefaultMutableTreeNode) tree.getSelectionPath().getLastPathComponent();
			
			currentLabel = selectedElement.getUserObject().toString(); 
			tempTextTreeNode = myTree.searchTree(currentLabel);
			
			if(button.getSource() == editLabel)
			{
				makeEditable("editLabel", true);
			}
			if(button.getSource() == saveLabel)
			{
				stringValue = label.getText();
				
				if(!myTree.isInTree(stringValue))
				{
					myTree.setLabel(tempTextTreeNode, stringValue);
					
					selectedElement.setUserObject(stringValue);
					treeModel.nodeChanged(selectedElement);
				}
				else
				{
					label.setText("There is a node with that label");
				}
				
				makeEditable("editLabel", false);
			}
			if(button.getSource() == editContent)
			{
				makeEditable("editContent", true);
			}
			if(button.getSource() == saveContent)
			{
				stringValue = content.getText();
				
				myTree.setContent(tempTextTreeNode, stringValue);
				
				makeEditable("editContent", false);
			}
			if(button.getSource() == search)
			{
				
				myTree.diagnosticPrint();
			}
			if(button.getSource() == add)
			{
				totalNodeCount++;
				DefaultMutableTreeNode tempNode;
				tempNode = addNode("new node " + totalNodeCount);
				tempNode = (DefaultMutableTreeNode) tempNode.getParent();
				tempTextTreeNode = myTree.searchTree(tempNode.toString());
				
				myTree.addNode(tempTextTreeNode, "new node " + totalNodeCount, "click edit to change text");
				
				setChildrenList(tempNode.toString());
			}
			if(button.getSource() == remove)
			{
				DefaultMutableTreeNode node;
				node = removeCurrentNode();
				
				tempTextTreeNode = myTree.searchTree(node.toString());
				myTree.clearSubtree(tempTextTreeNode);
			}
		}
		
	    public void makeEditable(String area, boolean editable)
	    {
	    	if(area.equals("editLabel"))
	    	{	
	    		label.setEditable(editable);
	    	}
	    	if(area.equals("editContent"))
	    	{
	    		content.setEditable(editable);
	    	}	
	    }
	}
			
    private class KeyPress implements KeyListener
    {
        public void keyPressed(KeyEvent key)
        {
            if(key.getKeyCode() == KeyEvent.VK_ENTER)
            {
                System.out.println("hey");
            	saveLabel.doClick();
            	label.transferFocusBackward();
            }
        }
        
        public void keyTyped(KeyEvent e){}
        public void keyReleased(KeyEvent e){}
    }   
}
