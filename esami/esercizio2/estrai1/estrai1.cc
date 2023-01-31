#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// *********************************************
// NON MODIFICARE QUESTO CODICE SOTTO
// *********************************************
typedef struct tree {
  int info;
  struct tree * left;
  struct tree * right;
} tree;

typedef struct _list {
  int info;
  struct _list * next;
} list;

void insert(tree * & result, const int num) {
		if (result == NULL) {
				result = new tree;
				// *result = {num, NULL, NULL};
				result->info = num;
                result->left = NULL;
                result->right = NULL;
		} else if (result->info > num) {
				insert(result->left, num);
		} else {
				insert(result->right, num);
		}
}
void print_tree(const tree * root, int spazio = 0){
		if (root != NULL) {
				spazio++;
				print_tree(root->right, spazio);

				for (int i = 1; i < spazio; i++) std::cout<<"  ";
				std::cout<<root->info<<"\n";
				print_tree(root->left, spazio);
		}
}

void delete_tree(tree * & root) {
  if (root != NULL) {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = NULL;
  }
}

void print_list(const list * l) {
  if (NULL == l) std::cout << std::endl;
  else {
    std::cout << l->info << (NULL != l->next ? " " : "");
    print_list(l->next);
  }
}

void delete_list(list * & head) {
  if (NULL != head) {
    list * t = head;
    delete_list(head->next);
    delete t;
    head = NULL;
  }
}
// *********************************************
// NON MODIFICARE QUESTO CODICE SOPRA
// *********************************************


// *********************************************
// Add hereafter the declaration of estrai
// *********************************************

list *estrai(const tree *t);

// *********************************************
// Add here above the declaration of estrai
// *********************************************

// *********************************************
// NON MODIFICARE IL MAIN SOTTO
// *********************************************
int main() {
		tree * root = NULL;

  insert(root, 5);  insert(root, 2);
  insert(root, 2);  insert(root, 4);
  insert(root, 4);  insert(root, 3);
  insert(root, 1);  insert(root, 1);
  insert(root, 8);  insert(root, 7);
  insert(root, 7);  insert(root, 6);
  insert(root, 10); insert(root, 9);
  insert(root, 9);  insert(root, 8);

		std::cout << "Initial tree: " << std::endl;
		print_tree(root);
		std::cout << std::endl;

  list * res = estrai(root);
  std::cout << "I valori estratti sono: " << std::endl;
  print_list(res);
  delete_tree(root);
  delete_list(res);
		return 0;
}
// *********************************************
// NON MODIFICARE IL MAIN SOPRA
// *********************************************


// *********************************************
// Add hereafter the definition of estrai
// *********************************************

list *inserisci(list *l, int info) {
    list *l1 = new list;
    l1->info = info;
    l1->next = l;
    return l1;
}

list *estrai_aux(const tree *t, list *l) {
    if (t == NULL) {
        return l;
    }
    l = estrai_aux(t->right, l);
    if (t->info % 2 == 0) {
        l = inserisci(l, t->info);
    }
    l = estrai_aux(t->left, l);
    return l;
}

list *estrai(const tree *t) {
    return estrai_aux(t, NULL);
}

// *********************************************
// Add here above the definition of estrai
// *********************************************
