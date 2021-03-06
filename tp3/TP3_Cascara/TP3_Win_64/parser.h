/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path del archivo a cargar
 * \param LinkedList
 * \return 1 en caso de error, o 0 en caso de exito
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path del archivo a cargar
 * \param LinkedList
 * \return 1 en caso de error, o 0 en caso de exito
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
