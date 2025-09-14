from flask import Flask, request
from flask import render_template

global container_input
container_input = ''

app = Flask(__name__)
@app.route("/", methods=['GET', 'POST'])
def calculate():
    global container_input
    if request.method == 'POST':
        value = request.form['input']
        if value != 'compute':                                          
            container_input+=str(value)
        else:
            if container_input != '':
                container_input = str(process(container_input))

        if value == 'AC':                                               
            container_input = ''
        elif value == 'DE':                                              
            container_input = container_input[:-3]

    return render_template("cal.html", display1=container_input)        

def sum(a,b):
    return float(a)+float(b)

def sub(a,b):
    return float(a)-float(b)

def product(a,b):
    return float(a)*float(b)

def division(a,b):
    return float(a)/float(b)
 
def modulus(a, b):
    return float(a)*(float(b)/100)


def process(equation):
    global container_input
    container_input = ''
    operator =''
    a = b = ''
    
    for index in range(len(equation)):
        if equation[index].isdigit() != True and equation[index] != '.':  
            operator = equation[index]
            a = equation[:index]                                          
            b = equation[index+1:]                                        

    try:
        float(a) + float(b)
    except:
        return 'could not be parsed'                                      
   
    if operator == '+':
        return sum(a,b)
    elif operator == '-':
        return sub(a,b)
    elif operator == '*':
        return product(a,b)
    elif operator == '/':
        return division(a,b)
    elif operator == '%':
        return modulus(a,b)
    else:
       return 'invalid operator'
    
if __name__ == "__main__":
    app.run(debug=True)