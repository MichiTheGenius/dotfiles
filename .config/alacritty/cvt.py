import yaml
import toml

# Load the YAML file
with open('tokyo-night.yaml', 'r') as yaml_file:
    yaml_content = yaml.safe_load(yaml_file)

# Convert and save to TOML
with open('tokyo-night.toml', 'a') as toml_file:
    toml.dump(yaml_content, toml_file)
