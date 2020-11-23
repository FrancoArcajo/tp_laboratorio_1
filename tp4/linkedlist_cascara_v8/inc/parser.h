#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


#endif // PARSER_H_INCLUDED

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path del archivo a cargar
 * \param LinkedList
 * \return 1 en caso de error, o 0 en caso de exito
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
