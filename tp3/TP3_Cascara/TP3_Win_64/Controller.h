
/**
 * \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path al archivo a cargar
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/**
 * \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 * \param path al archivo a cargar
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/**
 * \brief Aniade un empleado a la linkedlist
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_addEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Edita un empleado de la linkedlist
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_editEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Elimina un empleado de la linkedlist
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Lista los empleados de la linkedlist
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Ordena los empleados de la linkedlist
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee);

/**
 * \brief Guarda los datos en el archivo data.csv (modo texto).
 * \param path al archivo a guardar
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/**
 * \brief Guarda los datos en el archivo data.bin (modo binario).
 * \param path al archivo a guardar
 * \param Linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


