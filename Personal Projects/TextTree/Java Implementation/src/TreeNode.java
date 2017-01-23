
public class TreeNode
{
    TreeNode parent;
    TreeNode[] children;
    String label;
    String content;
    int childrenCount;
    boolean isLeaf;

    public TreeNode()
    {
        parent = null;
        children = null;
        childrenCount = 0;
        isLeaf = false;
        label = null;
        content = null;
    }
    
    public TreeNode(TreeNode parentNode, String labelName, String contentString, boolean leaf)
    {
        parent = parentNode;
        children = null;
        childrenCount = 0;
        isLeaf = leaf;
        label = labelName;
        content = contentString;
    }

    public void addChild(String labelName, String contentString)
    {
        int counter;
        TreeNode[] temp; 
        
        if(childrenCount == 0)
        {
            children = new TreeNode[1];
            children[0] = new TreeNode(this, labelName, contentString, true);
            childrenCount++;
            isLeaf = false;
        }
        else
        {
            temp = new TreeNode[childrenCount + 1];

            for(counter = 0; counter < childrenCount; counter++)
            {
                temp[counter] = children[counter];
            }

            temp[counter] = new TreeNode(this, labelName, contentString, true); 
            children = temp;
            childrenCount++;  
        }
    }

    public void shiftChildren(String labelName)
    {
        int counter, tempCounter = 0;
        TreeNode[] temp;     

        if(childrenCount == 1)
        {
            children = null;
            childrenCount = 0;
        }
        else
        {
            temp = new TreeNode[childrenCount - 1]; 

            for(counter = 0; counter < childrenCount; counter++)
            {
                if(!children[counter].label.equals(labelName))
                {
                    temp[tempCounter] = children[counter];    
                    tempCounter++;            
                }        
            }    

            children = temp;
            childrenCount--;     
        }    
    }

    public void printNode()
    {
        System.out.println("");
        System.out.println("Label: " + label);
        System.out.println("Content: " + content);
        
        if(this.isLeaf)
        {
            System.out.println("Leaf");
        }    
        else
        {
            System.out.println("Not a leaf");
        }

        if(this.parent != null)
        {
            System.out.println("The parent is: " + parent.label);
        }
        else
        {
            System.out.println("The parent is null");
        }
        
        System.out.println("");
    }
}
