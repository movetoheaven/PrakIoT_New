<!doctype html>
<html lang="en">
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Integrated Parking Database</title>  

      <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
    </head>

    <body>

      <table class="table table-hover">
        <thead>
          <tr>
            <th scope="col">No</th>
            <th scope="col">Date</th>
            <th scope="col">Availability</th>
          </tr>
        </thead>
        
        <tbody id="logs">
        <?php 
            include "connection.php";
            $index = 1;
            $query = mysqli_query($conn, "SELECT * FROM parked_logs");
            while($data=mysqli_fetch_array($query)){
        ?>
          <tr>
            <td><?php echo $index++; ?></td>
            <td><?php echo $data['Time']; ?></td>
            <td><?php echo $data['Availability']; ?></td>
          </tr>
        <?php } ?>
        </tbody>
      </table>  
    </body>
</html>