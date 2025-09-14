const display = document.querySelector('.display');
const buttons = document.querySelectorAll('button');

let currentInput = "";

buttons.forEach(button => {
  button.addEventListener('click', () => {
    const value = button.textContent;

    if (button.classList.contains('clear')) {
      currentInput = "";
      display.value = "";
    } 
    else if (button.classList.contains('backspace')) {
      currentInput = currentInput.slice(0, -1);
      display.value = currentInput;
    } 
    else if (value === "=") {
      try {
        currentInput = eval(currentInput).toString();  
      } catch {
        currentInput = "Error";  
      }
      display.value = currentInput;
    } 
    else {
      currentInput += value;
      display.value = currentInput;
    }
  });
});
