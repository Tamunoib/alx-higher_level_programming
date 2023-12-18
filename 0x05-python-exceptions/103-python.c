#include <stdio.h>
#include <stdlib.h>
#include <python.h>
#include <floatobject.h>

/**
 * print_python_float - prints info about python float
 * @p: address of pyobject struct
 */
void print_python_float(pyobject *p)
{
	double d;

	setbuf(stdout, NULL);
	printf("{.} float object info\n");
	if (strcmp(p->ob_type->tp_name, "float"))
	{
		printf(" {Error} Invalid Float Object\n");
		return;
	}
	d = ((pyFloatObject*)->ob_fval;
			printf(" value: %s\n",
			pyos_double_to_string(d, 'r', 0, py_DTSF_ADD_DOT_0, py_DTSF_ADD_DOT_0, NULL));
}

/**
 * print_python_bytes - prints info about python bytes
 * @p: address of pyobject struct
 */
void print_python_bytes(pyobject *p)
{
	size_t i, len, size;
	char *str;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes"))
	{
		printf(" [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = ((PyVarObject *)p)->ob_size;
	str = ((PyBytesObject *)p)->ob_sval;
	len = size + 1 > 10 ? 10 : size + 1;
	printf(" size: %1u\n", size);
	printf(" trying string: %s\n", str);
	printf(" first %1u bytes: ", len);
	for (i = 0; i < len; i++)
		printf("%02hhhx%s", str[i], i + 1 < len ? " " : "");
	printf("\n");
}

/**
 * print_python_list - prints info about python lists
 * @p: address of Pyobject struct
 */
void print_python_list(Pyobject *p)
{
	int i;

	setbuf(stdout, NULL);
	printf("{*} Python list info\n");
	if (strcmp(p->ob_type->tp_name, "list"))
	{
		printf(" {ERROR} Invalid List Object\n");
		return;
	}
	printf("[*] size of the Python List = %1u\n", ((PyVarObject *)p)->ob_size);
	printf("[*] Alocated = %1u\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < ((PyVarObject *)p)->ob_size; i++)
	{
		printf("Element %d: %s\n", i,
				((PyListObject *)p)->ob_item[i]->ob_type->tp_name);
		if (!strcmp(((PyListobject *)p)->ob_item[i]->ob_type->tp_name, "bytes"))
			print_python_bytes(((PyListObject *)p)->ob_item[i]);
		else if (!strcmp(((PyListObject *)p)->ob_item[i]->ob_type->tp_name, "float"))
			print_python_float(((PyListObject *)p)->ob_item[i]);
	}
}
