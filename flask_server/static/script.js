function handleSubmit(event) {
  event.preventDefault();
  
  const formData = new FormData(event.target);
  const messageDiv = document.getElementById('message');
  
  fetch('/login', {
    method: 'POST',
    body: formData,
  })
  .then(response => response.text())
  .then(text => {
    messageDiv.textContent = text;
    if (text.includes('exitoso')) {
      messageDiv.className = 'message success';
      event.target.reset(); // Limpiar los campos de entrada
    } else {
      messageDiv.className = 'message error';
    }
    messageDiv.style.display = 'block';
    setTimeout(() => {
      messageDiv.style.display = 'none';
    }, 5000);  // Ocultar el mensaje después de 5 segundos
  })
  .catch(error => {
    messageDiv.textContent = 'Error en el registro';
    messageDiv.className = 'message error';
    messageDiv.style.display = 'block';
    setTimeout(() => {
      messageDiv.style.display = 'none';
    }, 5000);  // Ocultar el mensaje después de 5 segundos
  });
}
