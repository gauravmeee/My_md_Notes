
HTML Structure
```html
<!DOCTYPE html>
<html>
	<head>
		<title> ... </title>
	</head>
	
	<body>
	.
	.
	.
	</body>
	
</html>
```

Heading 
```html
<!--Max Size-->
<h1> Heading 1 </h1>
<h2> Heading 2 </h2>
<h3> Heading 3 </h3>
<h4> Heading 4 </h4>
<h5> Heading 5 </h5>
<h6> Heading 6 </h6>
<!--Min Size-->
```

Paragraph
```html
<p>
	This is  Paragraph line 1
    This is Paragraph line 2
</p>
```

Text Style
```html
<em> This is Italic Text </em>
<strong> This is Bold Text </strong>
```

List
```html
<ul> These are Unordered list
	<li> Item x </li>
	<li> Item y </li>
</ul>

<ol> These are Ordered List
	<li> Item 1 </li>
	<li> Item 2 </li>
<ol>
```

HTML Links
```html
<!-- Directing Link -->
<a href="link.com"> This is a Link to link.com </a>

<!-- InterLink -->
<a href ="#Section2"> Click to Go to Section 2 </a>
<h3 id="Section2"> This is Section2 </h3>
```

Next Line
```html
... This is line 1 <br> This is line 2 ...
```

Table
```html
<table>
	<thead>
		<tr>
			<th> Column 1 Heading </th>
			<th> Column 2 Heading </th>
		</tr>
	</thead>
	
	<tbody>
	
		<tr>
		<td> Column 1 Data 1 </td>
		<td> Column 2 Data 1 </td>
		</tr>
		
		<tr>
		<td> Column 1 Data 2 </td>
		<td> Column 2 Data 2 </td>
		</tr>
		
	</tbody>
	
</table>
```

Image
```html
<img src="image.jpg" alt="Alternate Text" breadth="10px" height="10px">
```

Inline Style
```html
<!-- Style to Tags -->
<style>
	h2{ color: rgb(0, 232, 15);} 
	p{color: red;}
	body {background-color: rgb(97, 250, 255); }
</style>

<!-- Style to ids -->
<style>
	#id1{/* Style here will applied one element that contain id="id1" */}
	#id2{/* Style here will applied one element that contain id="id2" */}
</style>

<!-- Style to Class -->
<style>
	.class1{/*Style here will applied on all element with class="class1" */}
	.class2{/*Style here will applied on all element with class="class2" */}
</style>
```
