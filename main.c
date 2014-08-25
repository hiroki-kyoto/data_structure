#include "tree.h"

int main()
{
	tree* _t = create_tree();
	tree_set_root(_t, 10);
	printf("%d\n", tree_get_root(_t));
	if(tree_set_left_child(_t, 1)!=OK)
	{
		printf("[tree_get_left_child] Throws Error!\n");
	}
	printf("%d\n", tree_get_left_child(_t));
	tree_set_right_child(_t, 2);
	printf("%d\n", tree_get_right_child(_t));
	tree_to_father(_t);
	tree_set(_t, 3);
	printf("%d\n", tree_get(_t));
	tree_to_root(_t);
	tree_set(_t, 0);
	printf("%d\n", tree_get_root(_t));

	// add more nodes
	tree_to_left_child(_t);
	tree_set_left_child(_t,4);
	printf("%d\n", tree_get_left_child(_t));
	tree_set_right_child(_t, 5);
	printf("%d\n", tree_get_right_child(_t));
	tree_to_father(_t);
	tree_set_right_child(_t, 6);
	printf("%d\n", tree_get_right_child(_t));

	destroy_tree(_t);

	return 0;
}

// main.c
