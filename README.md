# Taller2
Benjamín Garcés 215459144 benjamin.garces@alumnos.ucn.cl Pablo Jorquera 215455637 pablo.jorquera@alumnos.ucn.cl

Datos presentes en el txt: Producto("Medicamentos,Analgésicos y Antipiréticos,Paracetamol 500mg,500,9718,100"),
Producto("Medicamentos,Analgésicos y Antipiréticos,Ibuprofeno 400mg,700,7856,100"),
Producto("Medicamentos,Analgésicos y Antipiréticos,Ácido Acetilsalicílico 500mg,300,8271,100"),
Producto("Medicamentos,Antibióticos,Amoxicilina 500mg,1200,5581,100"),
Producto("Medicamentos,Antibióticos,Azitromicina 250mg,1500,1607,100"),
Producto("Medicamentos,Antibióticos,Ciprofloxacino 500mg,1800,6985,100"),
Producto("Vitaminas y Suplementos,Vitaminas,Vitamina C 1000mg,800,8585,100"),
Producto("Vitaminas y Suplementos,Vitaminas,Vitamina D 1000 UI,1000,5266,100"),
Producto("Vitaminas y Suplementos,Vitaminas,Complejo B 100mg,600,1025,100"),
Producto("Vitaminas y Suplementos,Minerales,Calcio 500mg,500,9643,100"),
Producto("Vitaminas y Suplementos,Minerales,Hierro 65mg,700,5645,100"),
Producto("Vitaminas y Suplementos,Minerales,Magnesio 400mg,600,3662,100"),
Producto("Productos de Cuidado Personal,Cuidado de la piel,Crema hidratante facial,1500,5758,100"),
Producto("Productos de Cuidado Personal,Cuidado de la piel,Jabón facial,800,1332,100"),
Producto("Productos de Cuidado Personal,Cuidado de la piel,Protector solar SPF 50,2000,4539,100"),
Producto("Productos de Cuidado Personal,Cuidado del cabello,Champú anticaspa,1000,3188,100"),
Producto("Productos de Cuidado Personal,Cuidado del cabello,Acondicionador,800,9774,100"),
Producto("Productos de Cuidado Personal,Cuidado del cabello,Gel fijador,600,5267,100"),
Producto("Productos para Bebés,Leche de fórmula,Leche de fórmula etapa 1,1800,7147,100"),
Producto("Productos para Bebés,Leche de fórmula,Leche de fórmula etapa 2,2000,4340,100"),
Producto("Productos para Bebés,Leche de fórmula,Leche de fórmula etapa 3,2200,3975,100"),
Producto("Productos para Bebés,Pañales,Pañales talla M,1500,4206,100"),
Producto("Productos para Bebés,Pañales,Pañales talla G,1700,9980,100"),
Producto("Productos para Bebés,Pañales,Toallitas húmedas,800,7589,100"),
Producto("Productos de Primeros Auxilios,Vendajes,Venda elástica 5cm x 5m,500,9587,100"),
Producto("Productos de Primeros Auxilios,Vendajes,Venda adhesiva 10cm x 10m,700,6928,100"),
Producto("Productos de Primeros Auxilios,Vendajes,Apósitos estériles,300,9998,100"),
Producto("Productos de Primeros Auxilios,Antisépticos,Alcohol isopropílico 70%,800,3673,100"),
Producto("Productos de Primeros Auxilios,Antisépticos,Agua oxigenada 10 volúmenes,600,6241,100"),
Producto("Productos de Primeros Auxilios,Antisépticos,Povidona yodada 10%,1000,2470,100")


Funciones y métodos:

Cliente:

        ~Cliente();
        //Destructor de la clase Cliente

        void entregaNumeroClientes(int&, int&,queue<Cliente*>&,queue<Cliente*>&);
        //Este método solicita al usuario la cantidad de personas que hay y luego registra a cada una de ellas como cliente preferencial o no preferencial. 

        void registroClientes(int&, int&,queue<Cliente*>&,queue<Cliente*>&);
        //Este método registra a un cliente como preferencial o no preferencial según la elección del usuario.

        Cliente* nuevoClientePreferencial(int&);
        //Este método crea un nuevo cliente preferencial, solicitando al usuario el tipo de cliente preferencial.

        void separarClientesPreferenciales(queue<Cliente*>&);
        //Este método separa los clientes preferenciales en tres colas distintas según su tipo: tercera edad, discapacitados y embarazadas.

        int getNumeroAtencion();
        //Este método devuelve el número de atención del cliente.

        string getTipoCliente();
        //Este método devuelve el tipo de cliente (preferencial o no preferencial).

        void atencionCliente(Cliente*, HashMap*&, vector<int>);
        //Este método simula la atención a un cliente. Solicita al cliente los productos que desea comprar, verifica si están disponibles en la bodega, calcula el total de la compra y permite imprimir una boleta si el cliente lo desea.

Producto:

        ~Producto();
        //Destructor de la clase Producto.

        Producto* ingresarProductos(string);
        //Este método toma una cadena de datos de un producto y la descompone en sus componentes (categoría, subcategoría, nombre del producto, precio, ID y cantidad). Luego, crea un nuevo objeto Producto con estos datos y lo devuelve.

        void setCantidadProducto(int);
        //Este método actualiza la cantidad de stock del producto sumando la cantidad proporcionada como argumento a la cantidad actual.

        bool verificarIdProducto(int&, vector<int>);
        //Este método solicita al usuario un ID de producto y verifica si ese ID está presente en la lista de IDs de productos existentes. Si el ID es válido, devuelve true; de lo contrario, solicita al usuario que ingrese un ID válido.

        int agregarProducto(vector<int>, int&);
        //Este método solicita al usuario el ID del producto que desea agregar y la cantidad de stock que se añadirá al producto. 

        string getProducto();
        //Este método devuelve el nombre del producto.

        int getIdProducto();
        //Este método devuelve el ID del producto.

        int getCantidadProducto();
        //Este método devuelve la cantidad de stock del producto.

        int getPrecioProducto();
        //Este método devuelve el precio del producto.

        void actualizarProductos(string);
        //Este método actualiza el archivo de texto que almacena la información de los productos. Toma una cadena que representa toda la información de los productos y la escribe en el archivo "Productos.txt", sobrescribiendo su contenido anterior.

        string informacionProducto();
        //Este método devuelve una cadena que contiene toda la información del producto en un formato específico.

Main:

        void datosBodega(HashMap &bodega, vector<int> idProductos);
        // Este método muestra los datos de los productos en la bodega, incluyendo su ID, nombre y cantidad en stock.

        void actualizarDatosBodega(HashMap &bodega, vector<int> idProductos);
        // Este método actualiza los datos de la bodega en el archivo "Productos.txt", eliminando los productos que han sido atendidos.

        void atenderClientes(queue<Cliente>& clientes, queue<Cliente>& clientesPreferenciales, HashMap*& bodega, vector<int> idProductos);
        // Este método gestiona la atención de clientes en la farmacia, atendiendo primero a los clientes preferenciales y luego a los clientes regulares, mostrando los datos de la bodega antes de cada atención.

        void reabastecerBodega(HashMap &bodega, vector<int> idProductos);
        // Este método permite reabastecer la bodega con nuevos productos, solicitando al usuario la cantidad de productos a reabastecer y el ID de los productos a reabastecer.

        int menu(HashMap& bodega, vector<int> idProductos);
        // Este método muestra un menú al usuario y gestiona las opciones seleccionadas, llamando a las funciones correspondientes según la opción seleccionada.

        void cargarDatosBodega(HashMap &bodega, vector<int> &idProductos);
        // Este método carga los datos de los productos desde el archivo "Productos.txt" en la bodega y en el vector de IDs de productos.

        void farmacia();
        // Este es el punto de entrada de la aplicación. Crea una instancia de la bodega, carga los datos de la bodega, muestra el menú al usuario y luego actualiza los datos de la bodega antes de finalizar.

        int main();
        // La función principal del programa, que llama a la función farmacia() para ejecutar la aplicación de la farmacia.

Hashmap:

        void HashMap::rehash();
        // Este método duplica el tamaño de la tabla hash y reorganiza los elementos en función de la nueva capacidad, asegurándose de mantener el orden relativo de las claves.

        HashMap::HashMap(double maxLoadFactor);
        // Constructor de la clase HashMap con el factor de carga máximo especificado.

        void HashMap::insert(int key, Producto* value); 
        // Este método inserta un nuevo par clave-valor en la tabla hash, realizando rehash si el factor de carga excede el límite establecido.

        Producto* HashMap::get(int key);
        // Este método recupera el valor asociado con una clave dada en la tabla hash.
        
        void HashMap::erase(int key); 
        // Este método elimina el par clave-valor asociado con una clave dada de la tabla hash.

        int HashMap::getNumberOfElements(); 
        // Este método calcula y devuelve el número total de elementos almacenados en la tabla hash.

Nodo:

        Nodo(int key, Producto* value);
        //Constructor de Nodo.