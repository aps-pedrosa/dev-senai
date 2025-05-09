const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');
const cors = require('cors');

const app = express();
const PORT = 3000;

// Middleware
app.use(cors());
app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, 'public')));

// Constants
const MAX_CAPACITY = 3;

// In-memory database
let vehicles = [];
let nextId = 0;

// Routes
// Get all vehicles
app.get('/api/vehicles', (req, res) => {
  res.json(vehicles);
});

// Get only parked vehicles
app.get('/api/vehicles/parked', (req, res) => {
  const parkedVehicles = vehicles.filter(car => car.state === true);
  res.json(parkedVehicles);
});

// Park a new vehicle
app.post('/api/vehicles/park', (req, res) => {
  // Check if parking is full
  const parkedCount = vehicles.filter(car => car.state === true).length;
  
  if (parkedCount >= MAX_CAPACITY) {
    return res.status(400).json({ error: 'Estacionamento cheio!' });
  }
  
  // Create new vehicle entry
  const newVehicle = {
    id: nextId++,
    inTime: new Date(),
    outTime: null,
    elapsed: 0,
    price: 0,
    state: true
  };
  
  // Add to database
  vehicles.push(newVehicle);
  
  res.status(201).json(newVehicle);
});

// Retrieve a vehicle
app.post('/api/vehicles/retrieve/:id', (req, res) => {
  const vehicleId = parseInt(req.params.id);
  
  // Find the vehicle
  const vehicleIndex = vehicles.findIndex(car => car.id === vehicleId && car.state === true);
  
  if (vehicleIndex === -1) {
    return res.status(404).json({ error: 'Veiculo nao encontrado ou ja retirado' });
  }
  
  // Calculate time and price
  const vehicle = vehicles[vehicleIndex];
  vehicle.outTime = new Date();
  vehicle.elapsed = Math.floor((vehicle.outTime - vehicle.inTime) / 1000); // seconds
  vehicle.price = vehicle.elapsed * 0.01; // R$ 0.01 per second
  vehicle.state = false;
  
  // Format time for response
  const hours = Math.floor(vehicle.elapsed / 3600);
  const minutes = Math.floor((vehicle.elapsed % 3600) / 60);
  const seconds = vehicle.elapsed % 60;
  const formattedTime = `${hours.toString().padStart(2, '0')}:${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;
  
  res.json({
    vehicle,
    formattedTime
  });
});

// Export data to CSV
app.get('/api/report/csv', (req, res) => {
  // Create CSV content
  let csvContent = 'ID,Tempo (s),Preco,Estado\n';
  
  vehicles.forEach(car => {
    let elapsedTime = car.elapsed;
    if (car.state === true) {
      elapsedTime = Math.floor((new Date() - car.inTime) / 1000);
    }
    
    csvContent += `${car.id},${elapsedTime},${(elapsedTime * 0.01).toFixed(2)},${car.state ? 'Estacionado' : 'Saiu'}\n`;
  });
  
  // Set headers for file download
  res.setHeader('Content-Type', 'text/csv');
  res.setHeader('Content-Disposition', 'attachment; filename=relatorio.csv');
  
  res.send(csvContent);
});

// Start server
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
