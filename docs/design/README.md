# Проєктування бази даних

В рамках проекту розробляється: 
- модель бізнес-об'єктів 
- ER-модель
- реляційна схема

## Модель бізнес-об'єктів

@startuml
entity User <<ENTITY>> #ffe396
entity User.password <<TEXT>> #fcf4dc
entity User.mail <<TEXT>> #fcf4dc
entity User.login <<TEXT>> #fcf4dc
entity User.role <<ENTITY>> #ffe396
entity User.name <<TEXT>> #fcf4dc
entity User.id <<NUMBER>> #fcf4dc
entity User.organizationsId <<NUMBER>> #fcf4dc

User.password -d-* User
User.mail -d-* User
User.login -u-* User
User.role "0.*"--"1.1" User
User.name -r-* User
User.id -u-* User
User.organizationsId -u-* User

entity Role.name <<TEXT>> #fcf4dc
entity Role.permissionRate <<NUMBER>> #fcf4dc
entity Role.id <<NUMBER>> #fcf4dc

Role.name -d-* User.role
Role.permissionRate -d-* User.role
Role.id -d-* User.role

entity Guest <<ENTITY>> #ffe396
entity Guest.id <<NUMBER>> #fcf4dc

Guest.id -d-* Guest

entity Organizations <<ENTITY>> #ffe396
entity Organizations.id <<NUMBER>> #fcf4dc
entity Organizations.name <<TEXT>> #fcf4dc
entity Organizations.members <<TEXT>> #fcf4dc
entity Organizations.rating <<NUMBER>> #fcf4dc

Organizations "0.*"-l-"0.*" User
Organizations.id -l-* Organizations
Organizations.name -d-* Organizations
Organizations.members -d-* Organizations
Organizations.rating -d-* Organizations

entity Access <<ENTITY>> #ffe396
entity Access.id <<NUMBER>> #fcf4dc
entity Access.time <<DATETIME>> #fcf4dc

User "1.1"-d-"0.*" Access
Guest "1.1"-d-"0.*" Access
Organizations "1.1"-d-"0.*" Access
Access.id -r-* Access
Access.time -l-* Access

entity Post <<ENTITY>> #ffe396
entity Post.id <<NUMBER>> #fcf4dc
entity Post.name <<TEXT>> #fcf4dc
entity Post.title <<TEXT>> #fcf4dc
entity Post.description <<TEXT>> #fcf4dc
entity Post.uploadedAt <<DATETIME>> #fcf4dc
entity Post.updatedAt <<DATETIME>> #fcf4dc

Access "0.*"-d-"0.*" Post

Post.id -u-* Post
Post.name -u-* Post
Post.title -u-* Post
Post.description -u-* Post
Post.uploadedAt -u-* Post
Post.updatedAt -u-* Post

entity Data <<ENTITY>> #ffe396
entity Data.id <<NUMBER>> #fcf4dc
entity Data.name <<TEXT>> #fcf4dc
entity Data.format <<TEXT>> #fcf4dc
entity Data.size <<TEXT>> #fcf4dc
entity Data.uploadedAt <<DATETIME>> #fcf4dc

Data "0.*"-l-"1.1" Post
Data.id -d-* Data
Data.name -u-* Data
Data.format -l-* Data
Data.size -d-* Data
Data.uploadedAt -u-* Data

entity Category <<ENTITY>> #ffe396
entity Category.id <<NUMBER>> #fcf4dc
entity Category.name <<TEXT>> #fcf4dc
entity Category.description <<TEXT>> #fcf4dc

Category "0.1"--"0.*" Category
Category "1.1"-r-"1.1" Post
Category.name -u-* Category
Category.id -u-* Category
Category.description -r-* Category

entity Rating <<ENTITY>> #ffe396
entity Rating.id <<NUMBER>> #fcf4dc
entity Rating.value <<NUMBER>> #fcf4dc

Rating "1.1"-r-"1.1" Post
Rating.value -u-* Rating
Rating.id -d-* Rating

@enduml

## ER-модель

@startuml

entity "User" <<ENTITY>>  {
  + password <<TEXT>> 
  + mail <<TEXT>> 
  + login <<TEXT>> 
  + name <<TEXT>> 
  + id <<NUMBER>> 
  + organizationsId <<NUMBER>> 
}

entity "Role" <<ENTITY>>  {
  + name <<TEXT>> 
  + permissionRate <<INT>> 
  + id <<INT>> 
}

entity "Guest" <<ENTITY>>  {
  + id <<INT>> 
}


entity "Organizations" <<ENTITY>>  {
  + id <<INT>> 
  + name <<TEXT>> 
  + members <<TEXT>> 
  + rating <<NUMBER>> 
}

entity "Access" <<ENTITY>>  {
  + id <<INT>> 
  + time <<DATETIME>> 
}
entity "Post" <<ENTITY>>  {
  + id <<INT>> 
  + name <<TEXT>> 
  + title <<TEXT>> 
  + description <<TEXT>> 
  + uploadedAt <<DATETIME>> 
  + updatedAt <<DATETIME>> 
}
entity "Data" <<ENTITY>>  {
  + id <<INT>> 
  + name <<TEXT>> 
  + format <<TEXT>> 
  + size <<TEXT>> 
  + uploadedAt <<DATETIME>> 
}


entity "Category" <<ENTITY>>  {
  + id <<INT>> 
  + name <<TEXT>> 
  + description <<TEXT>> 
}

entity "Rating" <<ENTITY>>  {
  + id <<INT>> 
  + value <<NUMBER>> 
}

Role "1.1"-l->"1.1" User
User "0.*"-->"0.*" Organizations
User "1.1"-d->"0.*" Access
Organizations "1.1"-d->"0.*" Access
Guest "1.1"-d->"0.*" Access
Access "0.*"-d->"1.1" Post
Category "1.1"-l->"1.1" Post
Category "0.1"-r->"0.*" Category
Rating "1.1"-d->"1.1" Post
Data "0.*"-r->"1.1" Post

@enduml
