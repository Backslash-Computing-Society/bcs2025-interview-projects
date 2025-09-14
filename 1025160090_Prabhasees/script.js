document.addEventListener('DOMContentLoaded', () => {
    const taskInput = document.getElementById('task-input');
    const addButton = document.getElementById('add-button');
    const taskList = document.getElementById('task-list');
    const autoRemoveToggle = document.getElementById('auto-remove-toggle');
    const dateElement = document.querySelector('.date');
    const timeElement = document.querySelector('.time');

    const updateDateTime = () => {
        const now = new Date();
        const options = { weekday: 'short', day: 'numeric', month: 'short', year: 'numeric' };
        const dateString = now.toLocaleDateString('en-US', options);
        dateElement.textContent = dateString.replace(/,/g, '');
       
        const timeString = now.toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit', hour12: false });
        timeElement.textContent = timeString;
    };

    updateDateTime();
    setInterval(updateDateTime, 60000);

    const loadTasks = () => {
        const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
        tasks.forEach(task => addTaskToDOM(task.text, task.completed));

        const autoRemoveState = JSON.parse(localStorage.getItem('autoRemove')) || false;
        autoRemoveToggle.checked = autoRemoveState;
    };

    const saveTasks = () => {
        const tasks = [];
        taskList.querySelectorAll('li').forEach(li => {
            tasks.push({
                text: li.querySelector('.task-text').textContent,
                completed: li.classList.contains('completed')
            });
        });
        localStorage.setItem('tasks', JSON.stringify(tasks));
    };

    const removeTask = (li) => {
        li.remove();
        saveTasks();
    };

    const addTaskToDOM = (taskText, isCompleted = false) => {
        if (taskText.trim() === '') return;

        const li = document.createElement('li');
        li.classList.toggle('completed', isCompleted);

        const checkbox = document.createElement('input');
        checkbox.type = 'checkbox';
        checkbox.checked = isCompleted;
        checkbox.addEventListener('change', () => {
            li.classList.toggle('completed');
            if (autoRemoveToggle.checked && checkbox.checked) {
                setTimeout(() => {
                    removeTask(li);
                }, 300);
            }
            saveTasks();
        });

        const span = document.createElement('span');
        span.classList.add('task-text');
        span.textContent = taskText;

        li.appendChild(checkbox);
        li.appendChild(span);
        taskList.appendChild(li);
    };

    const addNewTask = () => {
        const taskText = taskInput.value.trim();
        if (taskText) {
            addTaskToDOM(taskText);
            taskInput.value = '';
            saveTasks();
        }
    };

    addButton.addEventListener('click', addNewTask);
    taskInput.addEventListener('keydown', (e) => {
        if (e.key === 'Enter') {
            addNewTask();
        }
    });

    autoRemoveToggle.addEventListener('change', () => {
        localStorage.setItem('autoRemove', autoRemoveToggle.checked);
    });

    loadTasks();
});
