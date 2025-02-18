# Programming and Data Analysis for Scientists: Test 2
### Overview
This repo contains a programme for generating and Visualising a random movement of disks.
### Navigating the repository
##### Log
``git log`` will provide the full log of this project
##### Tags
For navigating the log through tags you can use the following commands in the terminal
- ``git tags``, shows a lists of all versions. Tags follow semantic versioning
- ``git checkout <tag-name>``, allows you to work on older versions. In order to leave a split version use ``git checkout master``.
### Compilation and Visualising the Output

#### Makefile
A Makefile is provided for producing an executable only.
#### Python Wrapper
view.py has been adapted so that it runs the model's executable. Outputs model data into confs directory alongside visualisation of the data. 
### Major Changes

#### system
##### Fixes
- Recreated header file
- Re-implemented uniform function
- Fixed issue within step function where i in for loop was not being initialised to 0,
##### Developments
- Changed it so that the box could be rectangular by setting X and Y limits seperately.
#### disk
##### Fixes
- Recreated header file
- Re-implemented dist function
##### Developments
- Switched class attributes to being private and only accessible through setters and getters.

#### main.cpp
- Can now input parameters through terminal when running output

#### view.py
- Implemented python bindings so that the whole model can be run through view.py