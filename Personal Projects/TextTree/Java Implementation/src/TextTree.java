public class TextTree
{

    TreeNode root;
    TreeNode current;

    public TextTree()
    {
        root = null;
        current = null;
    }

    public TreeNode getChildNode(TreeNode currentNode, int childNumber)
    {
    	int max = currentNode.childrenCount;
    	
        if(currentNode.children != null && childNumber >= 0 && childNumber < max)
        {
            return currentNode.children[childNumber]; 
        }

        return currentNode;
    }

    public TreeNode getCurrentNode()
    {
        return current;
    }

    public TreeNode getRoot()
    {
        return root;
    }

    public TreeNode searchTree(String labelName)
    {
        return searchHelper(root, labelName);
    }
 
    public void addNode(TreeNode currentNode, String labelName, String contentString)
    {
        if(root == null)
        {
            root = new TreeNode(null, labelName, contentString, true);
            current = root;
        }
        else
        {
            currentNode.addChild(labelName, contentString);    
        }
    }
    
    public void clearTree()
    {
        if(!isEmpty())
        {   
            clearHelper(root);        
        }
    }
    
    
    public void clearSubtree(TreeNode currentNode)
    {
        if(!isEmpty() && currentNode != null)
        {   
            clearHelper(currentNode);        
        }
    }

    public void diagnosticPrint()
    {
        if(!isEmpty())
        {   
            printHelper(root);        
        }
        else
        {
            System.out.println( "The tree is empty." );
        }
    }
	
	public void setLabel(TreeNode currentNode, String labelString)
	{
	    if(currentNode != null)
	    {
	        currentNode.label = labelString;
	    }
	}
	
	public void setContent(TreeNode currentNode, String contentString)
	{
	    if(currentNode != null)
	    {
	        currentNode.content = contentString;
	    }    
	}
	
	public String getLabel(TreeNode currentNode)
	{
	    String localCopy;
	
	    if(currentNode != null)
	    {    
	    	//System.out.println( "label is: " + currentNode.label );
	        localCopy = currentNode.label;
	
	        return currentNode.label;
	    }
	        
	    return null;
	}
	
	public String getContent(TreeNode currentNode)
	{
	    String localCopy;
	
	    if(currentNode != null)
	    {    
	        localCopy = currentNode.content;
	
	        return localCopy;
	    }
	        
	    return null;
	}
	
	public String[] getChildrenString(TreeNode currentNode)
	{
		int index;
		String[] temp = {" "};
		
		if(currentNode.children != null)
		{
			temp = new String[currentNode.childrenCount];
			
			for(index = 0; index < currentNode.childrenCount; index++)
			{
				temp[index] = getLabel(currentNode.children[index]);
			}	
		}
		return temp;
	}
	
	public boolean isInTree(String stringLabel)
	{
		TreeNode temp = root;
		
		if(root.label.equals(stringLabel))
		{
			return true;
		}	
		
		return inTreeHelper(stringLabel, root);
	}
	
	public boolean inTreeHelper(String stringLabel, TreeNode currentNode)
	{
		int index;
		
	    if(currentNode.children == null && currentNode.childrenCount == 0)
	    {
	    	if(currentNode.label.equals(stringLabel))
	    	{
	    		return true;
	    	}	
	    	
	    	return false;
	    		
	    }    
		else
		{
	        for(index = 0; index < currentNode.childrenCount; index++)
	        {   
	        	if(inTreeHelper(stringLabel, currentNode.children[index]) || currentNode.children[index].label.equals(stringLabel))
	        	{
	        		return true;
	        	}
	        }
	        
	        return false;
	    } 	
	}
	
	public boolean isEmpty()
	{
	    if(root == null) 
	    {
	        return true;
	    }        
	
	    return false;
	}
	
	public void printHelper(TreeNode currentNode)
	{
	    int index;  
	
	    if(currentNode.children == null && currentNode.childrenCount == 0)
	    {
	        currentNode.printNode();
	    }    
		else
		{
	        currentNode.printNode();
		
	        for(index = 0; index < currentNode.childrenCount; index++)
	        {   
	            printHelper(currentNode.children[index]);
	        }
	    }    
	}
	
	public void clearHelper(TreeNode currentNode)
	{
		TreeNode temp;
		
		if(currentNode == root)
	    {
	    	root = null;
	    }	
		else
		{
			currentNode.parent.shiftChildren(currentNode.label);
		}		
	}
	
	
	public TreeNode searchHelper(TreeNode currentNode, String labelName)
	{
	    int index;  
		    
	    if(currentNode != null && currentNode.label.equals(labelName))
	    {
		    return currentNode; 
	    }
	    else
	    {
	        if(currentNode.children != null && currentNode.childrenCount != 0)
	        {
	            for(index = 0; index < currentNode.childrenCount; index++)
	            {
	                if(searchHelper(currentNode.children[index], labelName) != null)
	                {   
	                    return searchHelper(currentNode.children[index], labelName);
	                }
	            }
	            
	            return null;
	        } 
	        else
	        {
	            return null;
	        }   
	    }
	}

}
