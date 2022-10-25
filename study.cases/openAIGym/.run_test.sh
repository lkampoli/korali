#!/bin/bash

# Install openAI gym

python3 -m pip install gym[mujoco]

##### Running Test

# delete old test
rm -rf _result_vracer_HalfCheetah-v2_-1/

echo "Running ${file} ..."
python3 run-vracer.py --env HalfCheetah-v4 --exp 1000 --run -1
