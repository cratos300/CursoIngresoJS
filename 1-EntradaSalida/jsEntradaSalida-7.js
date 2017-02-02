/*Debemos lograr tomar Los numeros por ID ,
transformarlos a enteros (parseInt),realizar la operación correcta y 
mostar el resulto por medio de "ALERT"
ej.: "la Resta es 750"*/ 
function sumar()
{	var numero1
	var numero2
    numero1=document.getElementById("numeroUno").value;
    numero2=document.getElementById("numeroDos").value;
    numero1=parseInt(numero1)
    numero2=parseInt(numero2)
    var resultado=numero1+numero2
    var msj="la suma es de"+resultado
    alert(msj)
}
function restar()
{
	var numero1
	var numero2
    numero1=document.getElementById("numeroUno").value;
    numero2=document.getElementById("numeroDos").value;
	numero1=parseInt(numero1)
	numero2=parseInt(numero2)
	var resultado=numero1-numero2
	var msj= "la resta es de "+resultado
	alert (msj)
	
}

function multiplicar()
{ var numero1
	var numero2
    numero1=document.getElementById("numeroUno").value;
    numero2=document.getElementById("numeroDos").value;
    numero1=parseInt(numero1)
    numero2=parseInt(numero2)
    var resultado=numero1*numero2
    var msj= "la multiplicacion es de"+resultado
    alert (msj)

}

function dividir()
{var numero1
	var numero2
    numero1=document.getElementById("numeroUno").value;
    numero2=document.getElementById("numeroDos").value;
    numero1=parseInt(numero1)
    numero2=parseInt(numero2)
	var resultado=numero1/numero2
	var msj= "la division es de"+resultado
	alert (msj)



}

