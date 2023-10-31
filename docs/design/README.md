# Проєктування бази даних

В рамках проекту розробляється: 
- модель бізнес-об'єктів 
- ER-модель
- реляційна схема

## Модель бізнес-об'єктів

@startuml

entity User <> entity User.id <> entity User.login <> entity User.password <> entity User.mail <> entity User.name <> entity User.role <>

User "1.1" -- "0.*" Access
User.id -d-* User.login -d-* User.password -d-* User.mail -d-* User.name -d-* User

entity Guest <> entity Guest.id <>

Guest "1.1" -- "0.*" Access
Guest.id -d-* Guest

entity Role <> entity Role.name <> entity Role.id <> entity Role.permissionRate <>

Role "1.1" -d-* "0.*" User
Role.name -d-* Role.id -d-* Role.permissionRate -d-* Role

entity Access <>

Access "0.*" -- "0.*" Post

entity Post <> entity Post.id <> entity Post.name <> entity Post.title <> entity Post.description <> entity Post.uploadedAt <> entity Post.updatedAt <>

Post.id -d-* Post.name -d-* Post.title -d-* Post.description -d-* Post
Post.uploadedAt -l-* Post.updatedAt -l-* Post

entity Data <> entity Data.id <> entity Data.name <> entity Data.format <> entity Data.size <> Data.uploadedAt <>

Data "1.1" -- "1.1" Post
Data.id -u-* Data.name -u-* Data.format -u-* Data.size -u-* Data.uploadedAt -u-* Data

entity Category <> entity Category.id <> entity Category.name <> entity Category.description <>

Category "0.1" -- "0.*" Category
Category "1.1" -- "1.1" Post
Category.id -u-* Category.name -u-* Category.description -u-* Category

@enduml

## ER-модель

@startuml

entity "User" {
  id: Int
  login: Text
  password: Text
  mail: Text
  name: Text
  role: Text
}

entity "Access" {
}

entity "Guest" {
  id: Int
}

entity "Role" {
  name : Text
  id: Int
  permissionRate: Int
}

entity "Post" {
  id : Int
  name : Text
  title : Text
  description : Text
  uploadedAt : Date
  updatedAt : Date
}

entity "Data" {
  id : Int
  name : Text
  format : Text
  size : Int
  uploadedAt : Date
}

entity "Category" {
  id : Int
  name : Text
  description : Text
}

User "1.1" -- "0.*" Access
User "1.1" -- "0.*" Role
User "1.1" -- "1.1" Post
Access "0.*" -- "0.*" Post
Role "1.1" -- "0.*" User
Guest "1.1" -- "0.*" Access
Post "0.1" -- "0.*" Category
Post "1.1" -- "1.1" Data

@enduml
