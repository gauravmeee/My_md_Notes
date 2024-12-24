
# [THIS and arrow function in javascript | chai aur javascript](https://www.youtube.com/hashtag/javascript)
this in global statement in browser -> point to window
this in global statement in Nodejs -> point to empty object


Implicit Return works in Single line

Explicit Return 
```js
const addTwo = (numl, num2) => return { numl + num2 }
```

❌ Implicit Return will not work (Due to curly braces)
```js
const addTwo = (numl, num2) => { numl + num2 }
```

✅ Implicit Return
```js
const addTwo = (numl, num2) => ( numl + num2 )
```

✅ Implicit Return 
```js
const addTwo = (numl,num2) => numl + num2
```

