#!/bin/bash

# Define the filename to store employee records
filename="employee.txt"

# Function to add an employee record
add_employee() {
  echo "Enter Employee Name:"
  read name
  echo "Enter Employee Number:"
  read emp_number
  echo "Enter Telephone Number:"
  read tel_number

  echo "$emp_number|$name|$tel_number" >> "$filename"
  echo "Employee record added successfully."
}

# Function to delete an employee record
delete_employee() {
  echo "Enter Employee Number to delete:"
  read emp_number

  if grep -q "^$emp_number|" "$filename"; then
    sed -i "/^$emp_number|/d" "$filename"
    echo "Employee record deleted successfully."
  else
    echo "Employee not found."
  fi
}

# Function to search and display an employee record
search_employee() {
  echo "Enter Employee Number to search:"
  read emp_number

  if grep -q "^$emp_number|" "$filename"; then
    echo "Employee Details:"
    grep "^$emp_number|" "$filename"
  else
    echo "Employee not found."
  fi
}

# Function to display an employee record
display_employee() {
  echo "Enter Employee Number to display:"
  read emp_number

  if grep -q "^$emp_number|" "$filename"; then
    echo "Employee Details:"
    grep "^$emp_number|" "$filename"
  else
    echo "Employee not found."
  fi
}

# Function to sort and list all employee records
sort_records() {
  sort -t '|' -k 1 -o "$filename" "$filename"
  echo "Employee records sorted successfully."
}

# Function to list all employee records
list_all_records() {
  if [ ! -s "$filename" ]; then
    echo "No employee records found."
  else
    echo "Employee Records:"
    cat "$filename"
  fi
}

# Main menu
while true; do
  echo "Menu:"
  echo "1. Create Employee Record"
  echo "2. Delete Employee Record"
  echo "3. Search Employee Record"
  echo "4. Display Employee Record"
  echo "5. Sort Records"
  echo "6. List All Records"
  echo "7. Exit"

  read choice

  case $choice in
    1) add_employee;;
    2) delete_employee;;
    3) search_employee;;
    4) display_employee;;
    5) sort_records;;
    6) list_all_records;;
    7) echo "Exiting..."; exit;;
    *) echo "Invalid option. Please try again.";;
  esac
done

