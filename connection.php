<?php
//connection to database
$servername = "localhost";
$database = "datalogs";
$username = "root";
$password = "";

$conn = mysqli_connect($servername, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

echo "Connected successfully";


//write data to database
$Availability = $_GET["Availability"];

$query = "INSERT INTO parked_logs (Availability) VALUES ('$Availability')";
$result = mysqli_query($conn, $query);

if ($conn->query($query)) {
    echo "Inputted Data";
} else {
    echo "Error: " . $result . "<br>" . $conn->error;
}
