<h1>IoT-Based-Battery-Monitoring-System</h1>

<p>This project uses an Arduino to collect temperature data, battery status, and GPS coordinates, then sends it to ThingSpeak via GPRS.</p>

<h2>Features</h2>
<ul>
  <li>Reads temperature from DS18B20 sensor</li>
  <li>Monitors battery state-of-charge (SOC) and voltage using MAX17043 fuel gauge</li>
  <li>Tracks location via GPS module (NMEA output)</li>
  <li>Sends data to ThingSpeak IoT platform using SIM800L GPRS module</li>
</ul>

<h2>Hardware Requirements</h2>
<ul>
  <li>Arduino Uno/Nano</li>
  <li>SIM800L GPRS module</li>
  <li>NMEA-compatible GPS module (e.g., NEO-6M)</li>
  <li>DS18B20 temperature sensor</li>
  <li>MAX17043 battery fuel gauge IC</li>
  <li>Lithium battery (for monitoring)</li>
  <li>Appropriate resistors and wiring</li>
</ul>

<h2>Connections</h2>
<table>
  <tr>
    <th>Arduino Pin</th>
    <th>Component</th>
    <th>Connection</th>
  </tr>
  <tr>
    <td>2</td>
    <td>GPS TX</td>
    <td>GPS Module RX</td>
  </tr>
  <tr>
    <td>3</td>
    <td>GPS RX</td>
    <td>GPS Module TX</td>
  </tr>
  <tr>
    <td>4</td>
    <td>GPRS RX</td>
    <td>SIM800L TX</td>
  </tr>
  <tr>
    <td>5</td>
    <td>GPRS TX</td>
    <td>SIM800L RX</td>
  </tr>
  <tr>
    <td>6</td>
    <td>DS18B20 Data</td>
    <td>Temperature Sensor</td>
  </tr>
  <tr>
    <td>-</td>
    <td>MAX17043</td>
    <td>I2C (A4/A5)</td>
  </tr>
</table>

![jitendrasharma-eg (1)_page-0001](https://github.com/user-attachments/assets/a2747ab1-5f41-4b43-93d1-e5f6d5cbd9c5)


<h2>Setup</h2>
<ol>
  <li>Install required libraries:
    <ul>
      <li>SoftwareSerial</li>
      <li>OneWire</li>
      <li>DallasTemperature</li>
      <li>LiFuelGauge (for MAX17043)</li>
      <li>TinyGPS++</li>
    </ul>
  </li>
  <li>Configure ThingSpeak:
    <ul>
      <li>Create a channel at <a href="https://thingspeak.com">thingspeak.com</a></li>
      <li>Note your API key and update it in the code</li>
    </ul>
  </li>
  <li>GPRS Configuration:
    <ul>
      <li>Insert SIM card with active GPRS data plan</li>
      <li>Update APN in code (<code>airtelgprs.com</code> may need changing for your provider)</li>
    </ul>
  </li>
</ol>

<h2>Usage</h2>
<ol>
  <li>Upload the sketch to Arduino</li>
  <li>Power the system (ensure sufficient power for GPRS module)</li>
  <li>Data will be sent to ThingSpeak periodically</li>
</ol>

<h2>ThingSpeak Fields</h2>
<ul>
  <li><strong>Field1:</strong> Battery SOC (%)</li>
  <li><strong>Field2:</strong> Battery Voltage (V)</li>
  <li><strong>Field3:</strong> Temperature (°C)</li>
  <li><strong>Field4:</strong> Longitude</li>
  <li><strong>Field5:</strong> Latitude</li>
</ul>
📊 Live Data Visualization: Battery status and performance metrics are sent wirelessly to the cloud, enabling remote monitoring and predictive maintenance.
<h3>👨‍💻 Author</h3>
📬 Author: Jitendra Sharma 📧 Email: jitendrasharma7409@gmail.com 🔗 Follow for more: https://github.com/jitendrasharma-eng | www.youtube.com/@ECodeLab-mv4jm | linkedin.com/in/jitendra-sharma-484072248 [https://www.linkedin.com/in/jitendra-sharma-484072248?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BdRzhEpUKQSqQh6%2Fm6UayRw%3D%3D]
