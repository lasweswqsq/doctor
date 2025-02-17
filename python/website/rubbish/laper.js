const express = require('express');
const mysql = require('mysql');
 
const app = express();
const connection = mysql.createConnection({
  // 数据库配置
});
 
connection.connect();
 
app.get('/api/data', (req, res) => {
  connection.query('SELECT * FROM your_table', (error, results, fields) => {
    if (error) throw error;
    res.send(results);
  });
});
 
app.listen(3000, () => {
  console.log('Server running on port 3000');
});