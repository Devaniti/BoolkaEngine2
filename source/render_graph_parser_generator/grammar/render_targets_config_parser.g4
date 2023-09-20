parser grammar render_targets_config_parser;

options {
	tokenVocab = render_graph_lexer;
}

import common_parser, resource_formats_parser;

renderTargetsConfig: RENDER_TARGETS_CONFIG ID OPEN_CURLY_BRACKET renderTargetsConfig_body CLOSE_CURLY_BRACKET;

renderTargetsConfig_body: RENDER_TARGETS OPEN_SQUARE_BRACKET renderTargetEntry+ CLOSE_SQUARE_BRACKET;

renderTargetEntry: OPEN_CURLY_BRACKET renderTargetEntryBody CLOSE_CURLY_BRACKET;

renderTargetEntryBody: 
    renderTargetFormatDeclaration
    blendEnableDeclaration?
    srcBlendDeclaration?
    dstBlendDeclaration?
    blendOpDeclaration?
    srcBlendAlphaDeclaration?
    dstBlendAlphaDeclaration?
    blendOpAlphaDeclaration?
    writeMaskDeclaration?
    ;

renderTargetFormatDeclaration: FORMAT resourceFormatValue;
blendEnableDeclaration: BLEND_ENABLE boolValue;
srcBlendDeclaration: SRC_BLEND blendModeValue;
dstBlendDeclaration: DEST_BLEND blendModeValue;
blendOpDeclaration: BLEND_OP blendOpValue;
srcBlendAlphaDeclaration: SRC_BLEND_ALPHA blendModeValue;
dstBlendAlphaDeclaration: DEST_BLEND_ALPHA blendModeValue;
blendOpAlphaDeclaration: BLEND_OP_ALPHA blendOpValue;
writeMaskDeclaration: WRITE_MASK writeMaskValue (OR writeMaskValue)*;

blendModeValue: 
    BLEND_ZERO |
    BLEND_ONE |
    BLEND_SRC_COLOR |
    BLEND_INV_SRC_COLOR |
    BLEND_SRC_ALPHA |
    BLEND_INV_SRC_ALPHA |
    BLEND_DEST_ALPHA |
    BLEND_INV_DEST_ALPHA |
    BLEND_DEST_COLOR |
    BLEND_INV_DEST_COLOR |
    BLEND_SRC_ALPHA_SAT |
    BLEND_BLEND_FACTOR |
    BLEND_INV_BLEND_FACTOR |
    BLEND_SRC1_COLOR |
    BLEND_INV_SRC1_COLOR |
    BLEND_SRC1_ALPHA |
    BLEND_INV_SRC1_ALPHA |
    BLEND_ALPHA_FACTOR |
    BLEND_INV_ALPHA_FACTOR;

blendOpValue:
    BLEND_OP_ADD |
    BLEND_OP_SUBTRACT |
    BLEND_OP_REV_SUBTRACT |
    BLEND_OP_MIN |
    BLEND_OP_MAX;

writeMaskValue:
    MASK_ALL |
    MASK_RED |
    MASK_GREEN |
    MASK_BLUE |
    MASK_ALPHA |
    MASK_NONE;
