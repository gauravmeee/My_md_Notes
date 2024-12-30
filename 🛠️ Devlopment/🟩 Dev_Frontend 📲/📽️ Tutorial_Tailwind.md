
# [Tailwind CSS in one Video | Sigma Web Development Course - Tutorial #98](https://www.youtube.com/watch?v=-g969furGik&t=1714s&ab_channel=CodeWithHarry)


## How to setup Tailwind CSS

Step 1: Run the following commands

``` 
npm install -D tailwindcss
npx tailwindcss init
```

Step 2: Update tailwind.conf.js file to include this line:
```sh
# if using HTML
content: ["*.html"],

# if using ReactJS
content: [ './src/**/*.{js,jsx,ts,tsx}', ],
```

Step 3: Add the following lines to your `src/index.css` (or a custom CSS file):
```
@tailwind base;
@tailwind components;
@tailwind utilities;
```

Step 4: Include the src/output.css file to your html

Step 5: Run the following command:
```
npx tailwindcss -i ./src/input.css -o ./src/output.css --watch
```