import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

christmas_lights_ns = cg.esphome_ns.namespace('christmas_lights')
ChristmasLights = christmas_lights_ns.class_('ChristmasLights', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ChristmasLights)
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)