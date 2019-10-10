# ⚡️ Process Management In C

This simple script in C is a program that runs a process which forks a child process and passes arguments into the child process.

The child process then manipulates these arguments by e.g. writing them into a target `output.txt` file.

Meanwhile the parent process waits for the child to complete execution and then it will itself resume it's own execution.

This script also records and logs the duration of both processes respectively.

### 🚀 How to execute
Compile the parent script with `gcc`
```bash
 gcc ./parent.c -o parent
```

Compile the child script with `gcc`
```bash
gcc ./child.c -o child  
```

#### 🎠 Run the script
Here we pass a number like `23` as an argument for the parent process. This will result in the child process logging the string `"Child process string"` 23 times.
```bash
./parent 23
```

### 🍷 Enjoy!
Thank you for attending my TED talk. 👋🏼 Feel free to buy me a coffee if you would like to! :smile:

[☕️ Buy me a coffee!](https://www.buymeacoffee.com/dIlWof6x5)

### 🍇 Author 
Made with love by Jonathan Bakebwa.
👣 Github: [@codebender828](https://github.com/codebender828)
🦅 Twitter: [@codebender828](https://twitter.com/codebender828)
