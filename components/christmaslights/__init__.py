import esphome.codegen as cg
import esphome.config_validation as cv

from esphome.components import output
from esphome.const import CONF_OUTPUT_ID
from esphome import cpp_types

CONF_ENABLED = "enabled"
CONF_STRAND_1 = "strand1"
CONF_STRAND_2 = "strand2"

christmas_lights_ns = cg.esphome_ns.namespace('christmas_lights')
ChristmasLights = christmas_lights_ns.class_('ChristmasLights', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(CONF_OUTPUT_ID): cv.declare_id(ChristmasLights),
    cv.Required(CONF_ENABLED): cv.use_id(cpp_types.bool_),
    cv.Required(CONF_STRAND_1): cv.use_id(output.FloatOutput),
    cv.Required(CONF_STRAND_2): cv.use_id(output.FloatOutput)
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_OUTPUT_ID])
    yield cg.register_component(var, config)

    enabled = yield cg.get_variable(config[CONF_ENABLED])
    cg.add(var.set_enabled(enabled))

    strand1 = yield cg.get_variable(config[CONF_STRAND_1])
    cg.add(var.set_strand1(strand1))

    strand2 = yield cg.get_variable(config[CONF_STRAND_2])
    cg.add(var.set_strand2(strand2))
