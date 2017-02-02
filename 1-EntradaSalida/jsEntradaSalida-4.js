/* 
	Debemos lograr tomar un dato por 'PROMPT' 
	y lo muestro por 'getElementById' al presionar el botón 'MOSTRAR'
*/
function Mostrar() 
{
	var s
	s=prompt("elNombre");
	document.getElementById("elNombre").value=s;
	
}

