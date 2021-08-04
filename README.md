# Fast Quasi-Harmonic Weights for Geometric Data Interpolation.

This repo is a c++ implementation of the paper 

*	[**Fast Quasi-Harmonic Weights for Geometric Data Interpolation**](https://dl.acm.org/doi/abs/10.1145/3450626.3459801).

	Yu Wang and Justin Solomon.
	
	_ACM Transactions on Graphics 40(4)_.
	_ACM SIGGRAPH 2021_.
	[OpenAccessPaper](https://dl.acm.org/doi/abs/10.1145/3450626.3459801)

To clone the repo, run

`git clone --recurse-submodules https://github.com/wangyu9/qhw-code.git`

## Installation

To ease the installation of the dependencies, we provide a docker container. To build the docker container, run

`sudo docker build -t qhw .`

To start the docker container:

`docker run -it qhw`

optionally, you can use  `docker run  -v HOST-MACHINE-FOLDER:CONTAINER-MACHINE-FOLDER  -it qhw` to mount a volume to the docker container. 

Alternatively, you are welcome to install all the dependencies manually by following the Dockerfile. 

## Code Compilation 

To build the c++ project, either within the container or on your own linux machine: 

`cd qhw-code`

`mkdir build; cd build;`

`cmake ..; make;`

## Usage

To compute the weights for the examples that we provided in ./data, run the following commands

`./qhw -e /qhw/qhw/data/beast-H  --step_size 0.1 -n  4 --solver adamd --project --verbose 0`

The data file folder can be 
beast-H
bunny-H 
raptor-H 
elephant-H 
dragon-H
tibiman-H

The resulting weights are stored in the file "W.mtx". 

If the code runs correctly, expect to see the following smoothness energies for the provided examples: 

Example	|	Energy	|
|:--------|:--------|
beast-H	| 111.5	
bunny-H | 10509.6
raptor-H | 34585.9
elephant-H | 644.5
dragon-H | 134.5
tibiman-H | 36136.4



