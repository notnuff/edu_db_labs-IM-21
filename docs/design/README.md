# Проєктування бази даних

В рамках проекту розробляється: 
- модель бізнес-об'єктів 
- ER-модель
- реляційна схема

## Модель бізнес-об'єктів

@startuml

entity User <> entity User.id <> entity User.login <> entity User.password <> entity User.mail <> entity User.name

entity Guest <> entity Guest.id

entity Role <> entity Role.name <> entity Role.id <> entity Role.icon 

entity Access

entity Post <> entity Post.id <> entity Post.name <> entity Post.title <> entity Post.description <> entity Post.uploadedAt <> entity Post.updatedAt

entity Data <> entity Data.id <> entity Data.name <> entity Data.format <> entity Data.size <> Data.uploadedAt

entity Category <> entity Category.id <> entity Category.name

@enduml
