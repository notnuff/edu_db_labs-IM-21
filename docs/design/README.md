# Проєктування бази даних

В рамках проекту розробляється: 
- модель бізнес-об'єктів 
- ER-модель
- реляційна схема

## Модель бізнес-об'єктів

@startuml

entity User #ffe396
entity User.password #fcf4dc
entity User.mail #fcf4dc
entity User.login #fcf4dc
entity User.role #ffe396
entity User.name #fcf4dc
entity User.id #fcf4dc

User.password -d-* User
User.mail -d-* User
User.login -u-* User
User.role "0.*"--"1.1" User
User.name -r-* User
User.id -u-* User

entity Role.name #fcf4dc
entity Role.permissionRate #fcf4dc
entity Role.id #fcf4dc

Role.name -d-* User.role
Role.permissionRate -d-* User.role
Role.id -d-* User.role

entity Guest #ffe396
entity Guest.id #fcf4dc

Guest.id -d-* Guest

entity Organizations #ffe396
entity Organizations.id #fcf4dc
entity Organizations.name #fcf4dc
entity Organizations.members #fcf4dc
entity Organizations.rating #fcf4dc

Organizations.id -d-* Organizations
Organizations.name -d-* Organizations
Organizations.members -d-* Organizations
Organizations.rating -d-* Organizations

entity Access #ffe396

User "1.1"-d-"0.*" Access
Guest "1.1"-d-"0.*" Access
Organizations "1.1"-d-"0.*" Access

entity Post #ffe396
entity Post.id #fcf4dc
entity Post.name #fcf4dc
entity Post.title #fcf4dc
entity Post.description #fcf4dc
entity Post.uploadedAt #fcf4dc
entity Post.updatedAt #fcf4dc

Access "0.*"-d-"0.*" Post

Post.id -u-* Post
Post.name -u-* Post
Post.title -u-* Post
Post.description -u-* Post
Post.uploadedAt -u-* Post
Post.updatedAt -u-* Post

entity Data #ffe396
entity Data.id #fcf4dc
entity Data.name #fcf4dc
entity Data.format #fcf4dc
entity Data.size #fcf4dc
entity Data.uploadedAt #fcf4dc

Data "0.*"-l-"1.1" Post
Data.id -d-* Data
Data.name -u-* Data
Data.format -l-* Data
Data.size -d-* Data
Data.uploadedAt -u-* Data

entity Category #ffe396
entity Category.id #fcf4dc
entity Category.name #fcf4dc
entity Category.description #fcf4dc

Category "0.1"--"0.*" Category
Category "1.1"-r-"1.1" Post
Category.name -u- Category
Category.id -u- Category
Category.description -r- Category

entity Rating #ffe396
entity Rating.id #fcf4dc
entity Rating.value #fcf4dc

Rating "1.1"-r-"1.1" Post
Rating.value -u- Rating
Rating.id -d- Rating

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
Access "0.*" -- "0.*" Post
Role "1.1" -- "0.*" User
Guest "1.1" -- "0.*" Access
Post "0.1" -- "0.*" Category
Post "1.1" -- "1.1" Data

@enduml
