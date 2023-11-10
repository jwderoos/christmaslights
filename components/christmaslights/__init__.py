import esphome.codegen as cg
import esphome.config_validation as cv

from esphome.components import output
from esphome.const import CONF_OUTPUT_ID, CONF_OUTPUT

christmas_lights_ns = cg.esphome_ns.namespace('christmas_lights')
ChristmasLights = christmas_lights_ns.class_('ChristmasLights', cg.Component)

strand1 = 0.0
strand2 = 0.0

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ChristmasLights),
    cv.GenerateID(CONF_OUTPUT_ID): cv.declare_id(strand1),
    cv.Required("strand1"): cv.use_id(strand1),
    cv.GenerateID(CONF_OUTPUT_ID): cv.declare_id(strand2),
    cv.Required("strand2"): cv.use_id(strand2)
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_OUTPUT_ID])
    yield cg.register_component(var, config)

    strand1 = yield cg.get_variable(config[CONF_OUTPUT])
    cg.add(var.set_strand1(strand1))

    strand2 = yield cg.get_variable(config[CONF_OUTPUT])
    cg.add(var.set_strand2(strand2))
