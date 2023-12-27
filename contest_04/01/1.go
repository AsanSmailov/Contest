package main

import (
 "encoding/json"
 "fmt"
 "io/ioutil"
 "strconv"
)

type Task struct {
 UserID    int    `json:"user_id"`
 ID        int    `json:"id"`
 Title     string `json:"title"`
 Completed bool   `json:"completed"`
}

type Project struct {
 ProjectID int    `json:"project_id"`
 Tasks     []Task `json:"tasks"`
}

func main() {
    
 var userID string
 fmt.Scanln(&userID)
 userID1, _ := strconv.Atoi(userID)

 data, _ := ioutil.ReadFile("data.json")

 var projects []Project
 err := json.Unmarshal(data, &projects)
 if err != nil {
  return
 }
 
 completedTasks := 0
 for _, project := range projects {
  for _, task := range project.Tasks {
   if task.UserID == userID1 && task.Completed {
    completedTasks++
   }
  }
 }
 fmt.Println(completedTasks)
}