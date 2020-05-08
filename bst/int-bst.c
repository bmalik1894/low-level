#include "int-bst.h"
static int_bst_node_t * helper_insert(int_bst_node_t * t, int_bst_node_t * newnode);
static int_bst_node_t * helper_remove(int_bst_node_t * t, int n);
bool int_bst_find(int_bst_node_t * t, int n);
static int_bst_node_t * getMax(int_bst_node_t * t);

// INSERT FUNCTION
bool int_bst_insert(int_bst_node_t ** t_p, int n) {
    
    // Creation of new node
    int_bst_node_t * new_p = malloc(sizeof(new_p)); 
    new_p->data = n;
    new_p->left = NULL;
    new_p->right = NULL;

    if (new_p == NULL) {  // if malloc error, return false
        free(new_p);
        return false;
    }

    if (* t_p == NULL) { // if empty tree, root = n
        *t_p = new_p;
        return true;
    }
    
    *t_p = helper_insert(*t_p, new_p);
    return true;
}

// INSERT HELPER FUNCTION
static int_bst_node_t * helper_insert(int_bst_node_t * t, int_bst_node_t * newnode) {

	if(newnode-> data <= t->data) { // n smaller than t's data
        if (t->left == NULL) {
            t->left = newnode;
            return t;
            }
        else {
            t->left = helper_insert(t->left,newnode); // left recursion
            return t;
        }
    }

    if(newnode->data > t->data) { // n larger than t's data
        if (t->right == NULL) {
            t->right = newnode;
            return t;
            }
        else {
            t->right = helper_insert(t->right,newnode); // right recursion
            return t;
        }
    }
    else {
        return NULL;
    }
}


// FINDER FUNCTION
bool int_bst_find(int_bst_node_t * t, int n) { // easy to describe recursively
    if(t == NULL) { // case: empty tree; false
        return false;
    }
    if (t->data == n) { // case: data is n; true
        return true;
    }
    if (t->left == NULL && t->right == NULL) { // case: nowhere to go; false
        return false;
    }
    if(t->left != NULL && n <= t->data) { // case: n is smaller than data; recurse left
        int_bst_find(t->left, n);
    }
    if(t->right != NULL && n > t->data) { // case: n is larger; recurse right
        int_bst_find(t->right, n);
    }
    
    // else case
}

// REMOVE FUNCTION
void int_bst_remove(int_bst_node_t ** t_p, int n) {
    if(int_bst_find(*t_p,n)) { // checks that the element exists
        * t_p = helper_remove(*t_p,n);
    }

}

//removal helper helper
static int_bst_node_t * getMax(int_bst_node_t * t) { // make sure to do this on t->left
    if (t->right == NULL) { // just in case theres the max on the left is the root
        if(t->left != NULL) {
        return t;
        }
    }
    
    else if (t->right->right == NULL) {

        int_bst_node_t * tmp_node = t->right;
        t->right = t->right->left;
        free(t->right);
        t->right = NULL;
        return tmp_node;
    }

    else {
        getMax(t->right);
    }
}


static int_bst_node_t * helper_remove(int_bst_node_t * t, int n) { // try to stop at parent node of removal node
	if (t == NULL) { // if the list is empty
		return t;
	}

    if (t->data != n /*|| t->left->data != n || t->right->data != n*/) { // recurses to data point 
        if(n <= t->data) {
            int_bst_node_t * new_t = t;
            new_t->right = t->right;
            new_t->left  = helper_remove(t->left,n);
            free(t);
            return new_t;
        }
        else if(n > t->data) {
            int_bst_node_t * new_t = t;
            new_t->left = t->left;
            new_t->right  = helper_remove(t->right,n);
            free(t);
            return new_t;
        }
    }



    if (t->data == n) { // case: root is removal node
        if(t->left == NULL && t->right != NULL) { // no left node
                int_bst_node_t * tmp_node = t->right;
                free(t);
                return tmp_node;
        }
        if(t->left != NULL && t->right == NULL) { // no right node
                int_bst_node_t * tmp_node = t->left;
                free(t);
                return tmp_node;
        }
        if(t->right == NULL && t->left == NULL) { // no children
            free(t);
            return NULL;
        }
        if(t->right != NULL && t->left != NULL) { // both children
            int_bst_node_t * tmp_left = t->left;
            int_bst_node_t * max = getMax(t->left); // gets max node of left child
            max->right = t->right; // max node of left child
            if (max->data == tmp_left->data) max->left = tmp_left->left;
            else max->left = tmp_left;
            free(t);
            return max;
        } 
    } 




    // if(t->left->data == n) { // case: child of root is removal node
    //     if(t->left->left == NULL && t->left->right == NULL) {
    //         free(t->left);
    //         t->left = NULL;
    //         return t;
    //     }
        
    //     if(t->left->left == NULL && t->left->right != NULL) {
    //         int_bst_node_t * tmp_node = t->left->right;
    //         free(t->left);
    //         t->left = tmp_node;
    //         return t;
            
    //     }
    //     if(t->left->left != NULL && t->left->right == NULL) {
    //         int_bst_node_t * tmp_node = t;
    //         free(t->left);
    //         t->left = tmp_node;
    //         return t;
    //     }
    //     if(t->left->left != NULL && t->left->right != NULL) {
    //         int_bst_node_t * max = getMax(t->left->left);

    //     }

    // }

    // if(t->right->data == n) {
    //     if(t->right->left == NULL && t->right->right == NULL) {
    //         free(t->right);
    //         t->right = NULL;
    //         return t;
    //     }
        
    //     if(t->right->left == NULL && t->right->right != NULL) {
    //         int_bst_node_t * tmp_node = t->right->right;
    //         free(t->right);
    //         t->right = tmp_node;
    //         return t;
            
    //     }
    //     if(t->right->left != NULL && t->right->right == NULL) {
    //         int_bst_node_t * tmp_node = t->right->left;
    //         free(t->right);
    //         t->right = tmp_node;
    //         return t;
    //     }
    //     if(t->right->left != NULL && t->right->right != NULL) {
    //         // HARD PART
    //     }


    //     return t;
    //}

}

void int_bst_remove_all(int_bst_node_t ** t_p) { //recurse everywhere and free the data
    //while(*t_p != NULL) { // base case: if tree is empty, done
    //int dat = (int) * t_p->data;
    //int_bst_remove(*t_p,dat)
    //}
}

void int_bst_print_elements(int_bst_node_t * t, FILE * f, char * fmt) { // prints in-order
    if(t != NULL) {
        if(t->left != NULL) {
            int_bst_print_elements(t->left,f,fmt);
        }
        
        fprintf(f,fmt,t->data);
        
        if(t->right != NULL) {
            int_bst_print_elements(t->right,f,fmt);
        }
    }
}

void int_bst_print_as_tree(int_bst_node_t * t, FILE * f) {
    if(t == NULL) {
        fprintf(f,".");
    }
    else {
        fprintf(f,"%d\n",t->data);
        
        if(t->left != NULL) {
            fprintf(f,"  ");
            int_bst_print_as_tree(t->left,f);
        }
        
        if(t->right != NULL) {
            fprintf(f,"  ");
            int_bst_print_as_tree(t->right,f);
        }
    }

}