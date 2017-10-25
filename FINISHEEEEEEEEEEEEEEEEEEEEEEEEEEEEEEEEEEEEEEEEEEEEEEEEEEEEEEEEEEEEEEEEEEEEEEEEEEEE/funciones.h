typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int direccion;
    int numeroDeTarjeta;
    int estado;
}eProgramador;
typedef struct
{
    char patente[20];
    int marca ;
    int Identificador;
    int HorarioDeEntrada;
    int estado;
}eEstacionamiento;


/** \brief Muestra individualmente cada uno
 *
 * \param lista de structura
 * \param tamaño de la estrucutra
 * \return void(nada)
 *
 */
void mostrarProgramador(eProgramador lista);
/** \brief Buscar coincidencia de patentes en el array
 *
 * \param recibe array
 * \param recibe el dato a verificar
 * \param recibe el tamaño del array
 * \return devuelve -1 si no encontro, si encontro devuelve el indice
 *
 */
 int buscarPatente(eEstacionamiento listaAutomovil[], char coincidencia[], int tamAutomovil);
/** \brief Busqueda de marca audi con su estado en 1
 *
 * \param recibe el array de estacionamiento
 * \param recibe el array de cliente
 * \param recibe el tamaño del array de estacionamiento
 * \param recibe el tamaño del array de cliente
 * \return no devuelve nada
 *
 */
void BuscarAudi(eEstacionamiento Est[], eProgramador Pro[],int tamEst, int tamPro);
/** \brief carga datos en la estructura de estacionamiento
 *
 * \param recibe el array de estacionamiento
 * \param recibe el tamaño
 * \return no devuelve nada
 *
 */
 void hardcodearautomoviles(eEstacionamiento cars[],int tam);
 /** \brief carga datos en la estructura de cliente
  *
  * \param recibe el array de cliente
  * \param recibe el tamaño del array
  * \return no devuelve nada
  *
  */
  void hardcodearcliente(eProgramador cars[],int tam);

  /** \brief ordena los autos segun el horario de entrada y si son iguales segun su patente
   *
   * \param recibe el array de estacionamiento
   * \param recibe el tamaño del array
   * \return no devuelve nada
   *
   */
void ordenarAutomoviles(eEstacionamiento cars[], int tam);
   /** \brief muestra el ingreso de automovil segun su marca
    *
    * \param recibe el array de la estructura
    * \param
    * \return no devuelve nada
    *
    */
void mostrarIngresoDeAutomovileeeee(eEstacionamiento lista);

    /** \brief Recorre coincidencia y si encuentra muestra cliente con su coche
     *
     * \param recibe array de cliente
     * \param recibe array de estacionamiento
     * \param recibe tamaño del cliente
     * \param recibe tamaño del estacionamiento
     * \return no devuelve nada
     *
     */
void RecorrerAmbasFunciones(eProgramador listaPro[],eEstacionamiento listaEst[],int tamPro,int tamEst);

/** \brief  verifica que el id para ingresar al estacionamiento este ingresado en el cliente
 *
 * \param   recibe el array de cliente
 * \param   recibe el array de estacionamiento
 * \param  recibe el tamaño de cliente
 * \param  recibe el tamaño del array de estacionamiento
 * \return
 *
 */
 int Verificar (eProgramador listaPRO[],int id,int tam);
 /** \brief hace el alta del estacionamiento
  *
  * \param recibe el array de estacionamiento
  * \param recibe el array de cliente
  * \param recibe el tamaño de cliente
  * \param recibe el tamaño de estacionamiento
  * \return no devuelve nada
  *
  */
  void AltaDeEstacionamiento(eEstacionamiento lista[],eProgramador listaPro[], int tamPro,int tamEst);
  /** \brief modifica el
   *
   * \param recibe el array de cliente
   * \param recibe el tamaño del array
   * \return no devuelve nada
   *
   */
   void Modificar(eProgramador lista[], int tam);
    /** \brief hace una baja logica con el estado
     *
     * \param recibe el array de clientes
     * \param recibe el array de estacionamiento
     * \param recibe el tamaño del array de cliente
     * \param recibe el tamaño del array de estacionamiento
     * \param recibe 4 enteros para ir acumulando en las marcas
     * \return
     *
     */
int BajaProgramador(eProgramador lista[],eEstacionamiento listaEs[],int tamPro,int tamEst, int* Acum1,int* Acum2,int* Acum3,int* Acum4);

/** \brief hace un alta de cleinte
 *
 * \param recibe el array de cliente
 * \param recibe el tamaño del array
 * \return no devuelve nada
 *
 */
 void AltaProgramador(eProgramador lista[], int tam);
 /** \brief verifica si el id del cliente ya esta registrado
  *
  * \param recibe el array de cliente
  * \param recibe el dato a verificar
  * \return recibe el tamaño del array
  *
  */
  int BuscarProgramador2(eProgramador lista[],int dato,int tam);
  /** \brief muestra cliente individualmente
   *
   * \param recibe el cliente
   * \param
   * \return no devuelve nada
   *
   */
void mostrarProgramador(eProgramador lista);
    /** \brief muestra la lista de clientes en estado 1

    * \param recibe un array
    * \param devuelve tamaño
    * \return no retorna nada
    *
    */

void mostrarProgramadores(eProgramador lista[],int tam);
/** \brief verifica la marca
 *
 * \param recibe el automovil
 * \param
 * \return no retorna nada
 *
 */
 void mostrarIngresoDeAutomovil(eEstacionamiento lista);
/** \brief muestra los automoviles
*
* \param recibe un array
* \param recibe el tamaño
* \return no retorna nada
*
*/
void mostrarIngresoDeAutomoviles(eEstacionamiento lista[],int tam);
/** \brief inicializa el estado de clientes en 0
*
* \param recibe el array de clientes
* \param recibe el tamaño
* \return no devuelve nada
*
*/
void InicializarVector(eProgramador lista[], int tam);
/** \brief inicializa el array de estado de estacionamiento en 0
*
* \param recibe el array de estacionamiento
* \param recibe el tamaño del array
* \return no retorna nada
*
*/
void InicializarVector2(eEstacionamiento lista[], int tam);
/** \brief busca el primer lugar de estado en 0
*
* \param recibe el array
* \param recibe el tamaño
* \return devuelve el indice que esta libre en el caso que lo este, si no devuelve -1
*
*/
int buscarLibre(eProgramador lista[],int tam);
/** \brief Validar numero
 *
 * \param recibe una cadena
 * \param
 * \return retorna 0 si recibe letra y 1 si esta todo ok
 *
 */
 int NumeroDigito (char numero[]);
 /** \brief Muestra 1 solo nombre
  *
  * \param recibe el array de programadores
  * \param
  * \return no devuelve nada
  *
  */
  void mostrarProgramadorrrr(eProgramador lista);




