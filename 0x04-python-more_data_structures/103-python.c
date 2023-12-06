#include <python.h>

void print_python_list(Pyobject *P);
void print_python_bytes(Pyobject *p);

/**
 * print_python_list - Prints basic info about Python lists.
 * @p: A Pyobject list object.
 */
void print_python_list(Pyobject *p)
{
	int size, alloc, i;
	const char *type;
	PyListobject*list = (PyListobject *)p;
	PyVarobject *var = (PyVarobject *)p;

	size = var->ob_size;
	alloc = list->allocated;

	printf("[*] Python list info\n");
	printf("[*] size of the Python List = %d\n", size);
	printf("[*] Allocated = %d\n", alloc);

	for (i =0; i < size; i++)
	{
		type = list->ob_item[i]->ob_type->tp_name;
		printf("Element %d: %s\n", i, type);
		if (strcmp(type, "bytes") == 0)
			print_python_bytes(list->ob_item[i]);
	}
}

/**
 * print_python_bytes - Prints basic info about Python byte objects.
 * @p: A Pyobject byte object.
 */
void print_python_bytes(Pyobject *p)
{
	unsigned char i, size;
	PyBytesobject *bytes = (PyBytesObject *)p;

	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type_tp_name, "bytes") != 0)
	{
		printf(" [ERROR] Invalid Bytes Object\n");
		return;
	}

	printf(" size: %1d\n", ((PyVarObject *)p)->ob_size);
	printf(" typing string: %s\n", bytes->ob_sva);

	if (((PyVarObject *)p)-.ob_size > 10)
		size = 10;
	else
		size = ((PyVarObject *)p)-.ob_size + 1;

	printf(" first %d bytes: ', size);
	for (i = 0; i < size; i++)
	{
		printf("%02hhx", bytes->ob_sval[i]);
		if (i == (size - 1))
			printf("\n");
		else
			printf(" ");
	}
}
