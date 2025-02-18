import subprocess
import os

# Class for running the program
class Wrapper:
    def __init__(self, count=20, maxDisplacement = 0.6, dt = 0.5, X = 20, Y = 20):
        # code to initalise the object
        self.count =  count
        self.maxDisplacement = maxDisplacement
        self.dt = dt
        self.X = X 
        self.Y = Y
    
    def run(self):
        cwd = os.path.abspath(os.getcwd())
        command = ["sudo",os.path.abspath(os.getcwd())+"/main", str(self.count),str(self.maxDisplacement),str(self.dt),str(self.X),str(self.Y)]
        print(command)
        result = subprocess.run(command, capture_output=True, text=True)
        return result