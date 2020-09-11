
int sumar(int num1,int num2){
    int suma;
    suma = num1 + num2;

    return suma;
}

int restar (int num1, int num2) {
    int resta;
    resta = num1 - num2;

    return resta;
}
int multiplicar (int num1, int num2) {
    int multiplicacion;
    multiplicacion = num1 * num2;

    return multiplicacion;
}
float dividir (int num1, int num2) {
    float division;
    division = num1 / num2;

    return division;

}
int factorial (int numero){

    if(numero >= 13){
        return -1;
    }else if(numero <= 1){
        return 1;
    }else{
        return numero * factorial(numero - 1);
    }
}



