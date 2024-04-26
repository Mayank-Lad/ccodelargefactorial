from flask import Flask, render_template, request
import subprocess

app = Flask(__name__)

def factorial_c(n):
    # Compile the C code
    subprocess.run(["gcc", "-o", "factorial", "largefact.c"])
    
    # Execute the compiled C program and get the output
    result = subprocess.run(["./factorial"], input=str(n), text=True, capture_output=True)
    
    # Split the output into factorial result and time taken
    output_lines = result.stdout.split('\n')
    factorial_result = output_lines[0].strip()
    time_taken = output_lines[-2].split(': ')[-1].strip()
    
    return factorial_result, time_taken

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        number = int(request.form['number'])
        factorial_result, time_taken = factorial_c(number)
        return render_template('index.html', result=factorial_result, time_taken=time_taken)
    return render_template('index.html', result=None, time_taken=None)

if __name__ == '__main__':
    app.run(debug=True)
