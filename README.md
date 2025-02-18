# Programming and Data Analysis for Scientists: Test 2
### Overview
This repo contains a programme for generating and Visualising a random movement of disks.
### Navigating the repository
##### Log
For a full overview of the project you can consider the full log. Navigate the log using the following commands in the terminal:
- ``git log``, will provide the full log of this project.
- ``git checkout <commit>``, will let you view and edit the files for that specific commit. If you do make changes they must be saved before returning to Head
- ``git checkout master``, will return you to the current head of the master branch
##### Tags
For quicker navigation of the repository you can use tags. I have used semantic versioning for the tags of this project. Navigate tags using the following commands in the terminal:
- ``git tag``, shows a lists of all tags.
- ``git checkout <tag-name>``, allows you to work on older versions.
### Compilation and Visualising the Output

#### Makefile
A Makefile is provided for producing an executable only, this executable will be called ``main``.
#### Python Wrapper
Before ``view.py`` is run, the executable must be created (which can be done using ``make``) and a directory called ``/confs`` must exist in the same directory as ``view.py``.

A wrapper class is defined in ``disk_sys_wrapper.py``. This script is then imported into ``view.py``, which can be run to create the data and visualisation for the model. You can also alter the input the parameters for the model in ``view.py``.
### Major Changes
For this project I have made the following major changes to the originaly provided code.
#### system
- Recreated header file
- Re-implemented uniform function
- Fixed issue within step function where i in for loop was not being initialised to 0,
- Changed it so that the box could be rectangular by setting X and Y limits seperately.
#### disk
- Recreated header file
- Re-implemented dist function
- Switched class attributes to being private and only accessible through setters and getters.
#### main.cpp
- Can now input parameters through terminal when running the executable produced through compilation of ``main.cpp``.
#### view.py
- Created another python script called ``disk_sys_wrapper`` that contains a class for running the executable. This wrapper is imported into ``view.py``.