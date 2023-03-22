const express = require('express')
const app = new express()
const path = require('path')
const hbs = require('hbs')

const template_path = path.join(__dirname,'../templates/views')

app.set("view engine", "hbs");
app.set("views",template_path);

app.get("/",(req,res)=>{
    res.render("library");
})

app.listen(8000,()=>{
    console.log(`Server is running at 8000`);
})