# Ports Which I used Most

```sh
React: http://localhost:3000
Express: http://localhost:3000
Vite: http://localhost:5173
Flask: http://localhost:5000
MongoDB: http://localhost:27017
MySQL: http://localhost:3306
```

As both Express (often) and Create React App default to port `3000`. This can lead to a conflict when both the frontend and backend are running on the same machine and both try to use port `3000`. To Handle this, You can explicitly set a different port in your Express app, for example:
```js
// Express.js
const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
```
### What is a Port?
A **port** is a virtual point where network connections start and end. They help computers differentiate between multiple services or applications running on the same device. Ports allow a single computer or server to handle multiple network requests at the same time.

### How Ports Work
When data is sent over the internet, it is broken down into smaller pieces called packets. These packets contain both the source and destination IP addresses, as well as a port number. The port number tells the receiving computer which application or service should handle the incoming data.

### Why Ports are Important
- **Security:** Firewalls use port numbers to block or allow traffic to and from your network, protecting against unauthorized access.
- **Service Management:** Ports ensure that multiple services (e.g., web server, database, SSH) can run on the same machine without interfering with each other.
- **Traffic Routing:** Ports allow multiple connections to be distinguished and handled correctly by the operating system.


### Web Servers
- **HTTP (web traffic):** `80`
- **HTTPS (secure web traffic):** `443`

### Development Servers
- **Vite (React, Vue, Svelte, etc.):** `5173`
- **Create React App:** `3000`
- **Next.js:** `3000`
- **Angular CLI:** `4200`
- **Vue CLI:** `8080`
- **Gatsby:** `8000`
- **SvelteKit:** `5173`

### Backend Frameworks
- **Express (Node.js):** No default port, but commonly `3000`
- **Django (Python):** `8000`
- **Flask (Python):** `5000`
- **Ruby on Rails:** `3000`
- **Spring Boot (Java):** `8080`
- **Laravel (PHP):** `8000`

### Databases
- **MongoDB:** `27017`
- **MySQL/MariaDB:** `3306`
- **PostgreSQL:** `5432`
- **Redis:** `6379`
- **Elasticsearch:** `9200`

### Containers & Orchestration
- **Docker API:** `2375` (non-secure) / `2376` (secure)
- **Kubernetes API Server:** `6443`

### Version Control
- **Git (SSH):** `22`
- **Git (HTTP/HTTPS):** `80` / `443`

### Message Brokers
- **RabbitMQ:** `5672` (AMQP) / `15672` (Management UI)
- **Kafka:** `9092`

### Miscellaneous
- **GraphQL Playground:** `4000`
- **Webpack Dev Server:** `8080`
- **phpMyAdmin:** `8080`

These ports can usually be configured, but the ones listed above are their common defaults.Here are some common default ports used by various technologies:

### Web Servers
- **HTTP (web traffic):** `80`
- **HTTPS (secure web traffic):** `443`

### Development Servers
- **Vite (React, Vue, Svelte, etc.):** `5173`
- **Create React App:** `3000`
- **Next.js:** `3000`
- **Angular CLI:** `4200`
- **Vue CLI:** `8080`
- **Gatsby:** `8000`
- **SvelteKit:** `5173`

### Backend Frameworks
- **Express (Node.js):** No default port, but commonly `3000`
- **Django (Python):** `8000`
- **Flask (Python):** `5000`
- **Ruby on Rails:** `3000`
- **Spring Boot (Java):** `8080`
- **Laravel (PHP):** `8000`

### Databases
- **MongoDB:** `27017`
- **MySQL/MariaDB:** `3306`
- **PostgreSQL:** `5432`
- **Redis:** `6379`
- **Elasticsearch:** `9200`

### Containers & Orchestration
- **Docker API:** `2375` (non-secure) / `2376` (secure)
- **Kubernetes API Server:** `6443`

### Version Control
- **Git (SSH):** `22`
- **Git (HTTP/HTTPS):** `80` / `443`

### Message Brokers
- **RabbitMQ:** `5672` (AMQP) / `15672` (Management UI)
- **Kafka:** `9092`

### Miscellaneous
- **GraphQL Playground:** `4000`
- **Webpack Dev Server:** `8080`
- **phpMyAdmin:** `8080`

These ports can usually be configured, but the ones listed above are their common defaults.