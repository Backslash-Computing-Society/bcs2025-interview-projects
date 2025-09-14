document.addEventListener('DOMContentLoaded', () => {
    const darkModeToggle = document.getElementById('darkModeToggle');
    const body = document.body;
    const moonIcon = '<i class="fas fa-moon"></i>';
    const sunIcon = '<i class="fas fa-sun"></i>';

    // Function to set the theme
    const setTheme = (theme) => {
        if (theme === 'dark') {
            body.classList.add('dark-mode');
            darkModeToggle.innerHTML = sunIcon;
            localStorage.setItem('theme', 'dark');
        } else {
            body.classList.remove('dark-mode');
            darkModeToggle.innerHTML = moonIcon;
            localStorage.setItem('theme', 'light');
        }
    };

    // Check for saved theme in localStorage
    const currentTheme = localStorage.getItem('theme');
    if (currentTheme) {
        setTheme(currentTheme);
    }

    // Toggle theme on button click
    darkModeToggle.addEventListener('click', () => {
        if (body.classList.contains('dark-mode')) {
            setTheme('light');
        } else {
            setTheme('dark');
        }
    });
});