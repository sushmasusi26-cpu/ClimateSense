import random

def climate_risk_prediction(temperature, humidity, soil_moisture, rain_value, water_level):

    # Drought Risk
    if soil_moisture < 30 and temperature > 35:
        return "⚠ Drought Risk Detected"

    # Flood Risk
    elif rain_value < 400 and water_level > 700:
        return "⚠ Flood Risk Detected"

    # Cold Stress
    elif temperature < 15:
        return "⚠ Cold Weather Stress"

    else:
        return "✅ Climate Conditions Normal"


# Example sensor data (simulate real input)
temperature = 38
humidity = 60
soil_moisture = 25
rain_value = 500
water_level = 300

result = climate_risk_prediction(
    temperature,
    humidity,
    soil_moisture,
    rain_value,
    water_level
)

print("ClimateSense AI Result:")
print(result)
