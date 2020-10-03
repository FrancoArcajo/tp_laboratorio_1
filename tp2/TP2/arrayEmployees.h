#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct {

int id;
char nombre[51];
char apellido[51];
float salario;
int sector;
int isEmpty;

} eEmpleado;

#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief Inicializa el campo isEmpty en 1.
 *
 * \param Array de los empleados.
 * \param Tamaño del array.
 * \return 0 si hay fallo, 1 si no hay fallo
 *
 */

int initEmployees(eEmpleado empleados[], int tam);

/** \brief Menu principal del ABM
 *
 * \return La opcion que el usuario seleccione.
 *
 */


int menu();

/** \brief Añade empleado al array de empleados.
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \param Id del empleado.
 * \return si hubo fallos un 0, sin fallos un 1
 *
 */

int addEmployees(eEmpleado empleados[], int tam, int id);

/** \brief Busca un empleado dentro del array  de empleados por medio del id.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \param Id del empleado.
 * \return Indice donde se encuentra el empleado encontrado por medio del id.
 *
 */

int findEmployeeById(eEmpleado empleados[], int tam, int id);

/** \brief Da de baja a un empleado de la lista cambiando el campo isEmpty a 1.
 *
 * \param Array de empleados.
 * \param Tamaño de array.
 * \return 0 si no hay fallos, 1 si hay fallos, 2 si la modificacion es cancelada por el usuario.
 *
 */

int removeEmployee(eEmpleado empleados[], int tam);

/** \brief Ordena el array de empleados por Apellido y Sector.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return si hay fallos 1, si no hay fallos 0
 *
 */

int sortEmployees(eEmpleado empleados[], int tam, int criterio);

/** \brief Imprime lista de empleados.
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \return si hay fallo 0, si no hay fallo 1.
 *
 */

int printEmployees(eEmpleado empleados[], int tam);

/** \brief Imprime datos de un empleado.
 *
 * \param Muestra un empleado.
 */

void printEmployee(eEmpleado empleado);

/** \brief Busca un empleado dentro del array por medio del id,
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return El indice del array del lugar de empleado libre.
 *
 */

int buscarLibre(eEmpleado empleados[], int tam);

/** \brief Modifica los campos de la estructura Empleados por medio del id.
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \return 0 si no hay fallos, 1 si hay fallos, 2 si la modificacion es cancelada por el usuario.
 *
 */

int modificarEmpleado(eEmpleado empleados[], int tam);

/** \brief Imprime total de empleados, salarios y promedio.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 *
 */

void informarSalario (eEmpleado empleados[], int tam);




