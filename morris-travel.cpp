void bst_morris_inorder(struct bst_node *root)  
{  
    struct bst_node *p = root, *tmp;  
    while (p) {
        //负责输出，取下一个
        if (p->left == NULL) {  
            printf("%d ", p->key);  
            p = p->right;  
        }  
        //做两件事，1.画当前节点的前驱节点链接，2将链接清除
        else {  
            tmp = p->left;  
            while (tmp->right != NULL && tmp->right != p)  
                tmp = tmp->right;
            //当前节点左子树的最右节点，即当前节点的前驱节点
            if (tmp->right == NULL) { 
                //画链接，然后取下一个继续画
                tmp->right = p;  
                p = p->left;  
            }  
            else {
                //将链接清除，并输出当前节点，取下一个
                printf("%d ", p->key);  
                tmp->right = NULL;  
                p = p->right;  
            }  
        }  
    }  
}  
