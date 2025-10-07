
### Sitemap and robots.tx

**Sitemap** and **robots.txt** are both tools that help search engines crawl and index your website efficiently, but they serve different purposes.

**Sitemap**

- A sitemap is an XML file that lists all important pages of your website.
- It tells search engines which pages exist and how to access them.
- Helps search engines discover pages that might not be easily reachable through normal navigation.
- Can include metadata like: last updated, change frequency, priority.
- Example:
```xml
<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
  <url>
    <loc>https://www.example.com/</loc>
    <lastmod>2025-09-05</lastmod>
    <changefreq>daily</changefreq>
    <priority>1.0</priority>
  </url>
  <url>
    <loc>https://www.example.com/about</loc>
    <lastmod>2025-09-01</lastmod>
    <changefreq>monthly</changefreq>
    <priority>0.8</priority>
  </url>
</urlset>
```

**robots.txt**
- A plain text file placed at the root of your website (`example.com/robots.txt`).
- Tells search engine crawlers which pages or folders they **can** or **cannot** access.
- Useful for preventing indexing of private pages or admin sections.
- Syntax is simple: `User-agent` specifies the crawler, `Disallow` blocks paths, `Allow` permits paths.
- Example:
    
```
User-agent: *
Disallow: /admin/
Allow: /public/
Sitemap: https://www.example.com/sitemap.xml
```

**Key differences:**

- Sitemap is for **telling search engines what to crawl**; robots.txt is for **telling them what not to crawl**.
- Both together guide search engines efficiently and improve SEO.
