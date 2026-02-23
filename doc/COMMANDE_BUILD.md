# Builder tout le workspace
colcon build

# Builder un seul package
colcon build --packages-select my_package

# Builder avec symboles de debug
colcon build --cmake-args -DCMAKE_BUILD_TYPE=Debug

# Source les fichiers setup d'abord
source install/setup.bash

# Debugger avec gdb directement
ros2 run --prefix "gdb -ex run --args" my_package my_node

# Debugger avec gdbserver (pour debug distant)
ros2 run --prefix "gdbserver :3000" my_package my_node

# Debugger avec valgrind (détection de fuites mémoire)
ros2 run --prefix "valgrind --leak-check=full" my_package my_node

# Source les fichiers setup d'abord
source install/setup.bash

# Debugger avec gdb directement
ros2 run --prefix "gdb -ex run --args" my_package my_node

# Debugger avec gdbserver (pour debug distant)
ros2 run --prefix "gdbserver :3000" my_package my_node

# Debugger avec valgrind (détection de fuites mémoire)
ros2 run --prefix "valgrind --leak-check=full" my_package my_node

# 1. Builder avec symboles de debug
colcon build --packages-select my_package --cmake-args -DCMAKE_BUILD_TYPE=Debug

# 2. Source
source install/setup.bash

# 3. Lancer avec gdb
ros2 run --prefix "gdb -ex run --args" my_package my_node