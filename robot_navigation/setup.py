## ! DO NOT MANUALLY INVOKE THIS setup.py, USE CATKIN INSTEAD
#!/usr/bin/env python

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

# fetch values from package.xml
setup_args = generate_distutils_setup(
    scripts=['scripts/check_node_is_alive', 'scripts/check_node_is_alive_server'],
    packages=['goal_checker_server'],
    package_dir={'': 'src'},
)

setup(**setup_args)
