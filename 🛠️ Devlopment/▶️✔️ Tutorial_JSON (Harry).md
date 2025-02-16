# [JSON Tutorial in Hindi 🔥🔥](https://youtu.be/whNFPBEI-wM)

Earlier XML is used for APIs
JSON - Java Script Object Notation

Syntax - Single Quotes are not allowed JSON.
## Creating a `JSON` Object
```json
{
	// "Property Keys" : Property Values
	"name" : "Gaurav",  // String : String
	"score" : 11.75 ,    //String : Number
	"isAdmin" : false ,   //String : Boolean
	"license" : null      //String : 
}
```
Note: Property Keys are always String (Double Quoted)
While using JSON in programs, Error are not shown. So it is difficult to find the bug.
### Parsing `JSON` into `JavaScript` Object

Write in Console
```js
//Assigning JSON to Variable
myJSON = `{
	"name" : "Gaurav",
	"score" : 11.75 , 
	"isAdmin" : false , 
	"license" : null
}`;

// Return: "{\n  \"name\": \"Gaurav\",\n  \"Score\": 11.75,\n  \"isAdmin\": fase\n  \"license\": null\n}"
```

```js
// Parisng 
JSON.parse(myJSON);

//Return: {name: "Harry", score: 11.75, isAdmin: false license: null}
```
Note: use `backticks`  to assign `json` string to variable

## Adding Array and Objects in JSON as Value
```js
myJSON = `{
	"name" : "Gaurav",
	"score" : 11.75 , 
	"isAdmin" : false , 
	"license" : null,
	"shopItems" : [ "food", "clothes", "sunflower oil"],
	"myObj" : {
		"name" : "nested",
		"marks" : 45
	}
}`;

//'{\n\t"name" : "Gaurav",\n\t"score" : 11.75 , \n\t"isAdmin" : false , \n\t"license" : null,\n\t"shopItems" : [ "food", "clothes", "sunflower oil"],\n\t"myObj" : {\n\t\t"name" : "nested",\n\t\t"marks" : 45\n\t}\n}'

JSON.parse(myJSON)
//{name: 'Gaurav', score: 11.75, isAdmin: false, license: null, shopItems: Array(3), …}

// Return Details : 

// isAdmin: false
// license: null
// myObj:
// marks: 45
// name: "nested"
// name: "Gaurav"
// score: 11.75
// shopItems: Array(3)
// 0: "food"
// 1: "clothes"
// 2: "sunflower oil"
// length: 3
```

Accessing Elements.
```js
myJSON = `{
	"name" : "Gaurav",
	"score" : 11.75 , 
	"isAdmin" : false , 
	"license" : null,
	"shopItems" : [ "food", "clothes", "sunflower oil"],
	"myObj" : {
		"name" : "nested",
		"marks" : 45,
		"shopItem2" : ["food", "clothers", {"a", true}]
	}
}`;

parsed = JSON.parse(myJSON);

parsed["isAdmin]
// false

parsed["shopItem"][2]
// "sunflower oil"

parsed["shopItem2"] ❌ // Can't Access Nested Object direclty
// Undefined

parsed["myObj"]["shopItem2"] ✅
//  (3) ["food", "clothes", {...}]

parsed["myObj"]["shopItem2"]["a"] ❌ // Can't Access Object in Array without Index direclty
// Undefined

pparsed["myObj"]["shopItem2"][2]["a"] ✅
// true
```
Note: Last`commas(,)`  is invalid in JSON if there is no next element after it


Summary: 
In JSON : you can use strings, boolea;n , numbers, nulls, array.
You can even nest object in it, you can nest object up to any level,
You can event put array in object, than a new object in the array, and again a array in the object and repeat up to any level.

It is good habit to make JSON Readable


# -------------------- The End ✅---------------------