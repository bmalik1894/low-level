#include "int-bst.h"
static int_bst_node_t * helper_insert(int_bst_node_t * t, int_bst_node_t * newnode);
bool int_bst_find(int_bst_node_t * t, int n);


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

    // if (int_bst_find(* t_p, n) == true) { // if node already in tree, return false
    //     free(new_p);
    //     printf("\nalready_in_tree\n");
    //     return false;
    // }

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

void int_bst_remove(int_bst_node_t ** t_p, int n) {
    if(int_bst_find(*t_p,n)) {
    * t_p = helper_remove(*t_p,n);
    }
    // if empty tree, stop
    // if left == null && right == null, go back one and remove left/right
    // if left == null, root = right
    // if right == null root = left
    // else keep going left until left == null. 
}

/*
 * helper for remove --  returns list with item(s) removed
 *
 * recursive strategy:
 *
 * if empty list, new list is list
 *
 * else if item smaller than head of list, not in list, so new list is just
 * list
 *
 * else if item matches head of list, new list is rest of list, with any
 * other occurrences of item removed
 *
 * else new list is list's head followed by result of removing item from 
 * rest of list
 */

static int_bst_node_t * passUpMax(int_bst_node_t * t) {
    if (t->right == NULL) {
        return t;
    }
}

static int_bst_node_t * getMax(int_bst_node_t * t) {
    if (t->right == NULL) {
        return t;
    }
    else {
        return getMax(t->right);
    }
}


static int_bst_node_t * helper_remove(int_bst_node_t * t, int n) {
	if (t == NULL) { // if the list is empty
		return t;
	}



    if(t->left->data == n) {
        if(t->right->data == NULL) {
            int_bst_node_t * new_tree = t;
            free(t->left);
            t->left = NULL;
            return new_tree;
        }

    }

    










	// else if (t->data == n) {
	// 	/* element in list -- remove this one and recurse */
	// 	int_bst_node_t *new_list = helper_remove(t->next, n);
	// 	free(t);
	// 	return new_list;
	// }
	// else {
	// 	/* element could be in list, but later -- recurse */
	// 	int_bst_node_t *new_list = 
	// 		helper_remove(t->next, n);
	// 	t->next = new_list;
	// 	return lst;
	// }
}

void int_bst_remove_all(int_bst_node_t ** t_p) { //recurse everywhere and free the data
    if(t_p == NULL) { // base case: if tree is empty, done
    NULL;
    }
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

}