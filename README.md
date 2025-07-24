#Project page URL
https://roadmap.sh/projects/task-tracker

# How to build with Visual Studio 
- Opend the folfer in Visual Studio
- Build the project
- This will generate the task-cli executable in the build directory.

# How to build manually with cmake
- mkdir build
- cd build
- cmake ..
- cmake --build .
- This will generate the task-cli executable in the build directory.

# Run
- Run the following syntax from your teminal : ./task-cli <command> [arguments]

# Task Tracker - Available Commands:
  add "description"           : Add a new task
  update <id> "description"   : Update the description of a task
  delete <id>                 : Delete a task by ID
  mark-in-progress <id>       : Mark a task as in progress
  mark-done <id>              : Mark a task as done
  list                        : List all tasks
  list done                   : List completed tasks
  list todo                   : List tasks that are not yet done
  list in-progress            : List tasks in progress
  help                        : Show this help message
  
# Examples 
./task-cli add "Buy groceries"
./task-cli update 1 "Buy groceries and cook dinner"
./task-cli mark-in-progress 1
./task-cli mark-done 1
./task-cli delete 1
./task-cli list
./task-cli list done
./task-cli list todo
./task-cli list in-progress
./task-cli help

# All tasks are stored in a file named tasks.json located in the current directory.